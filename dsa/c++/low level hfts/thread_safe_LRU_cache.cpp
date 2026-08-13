#include <bits/stdc++.h>
using namespace std;

class ThreadSafeLRUCache
{
public:
    ThreadSafeLRUCache(size_t capacity)
        : capacity_(capacity), head_(new Node()), tail_(new Node())
    {
        head_->next = tail_;
        tail_->prev = head_;
    }

    ~ThreadSafeLRUCache()
    {
        Node *current = head_;
        while (current)
        {
            Node *next = current->next;
            delete current;
            current = next;
        }
    }

    bool try_get(int key, int &value)
    {
        Node *node = nullptr;
        {
            lock_guard<mutex> map_lock(map_mtx_);
            auto it = cache_.find(key);
            if (it == cache_.end())
                return false;
            node = it->second;
        }

        unique_lock<mutex> node_lock(node->mtx);
        value = node->value;
        if (node->next != tail_)
            move_to_back(node, move(node_lock));
        return true;
    }

    void put(int key, int value)
    {
        Node *node = nullptr;
        {
            lock_guard<mutex> map_lock(map_mtx_);
            auto it = cache_.find(key);
            if (it != cache_.end())
            {
                node = it->second;
            }
            else
            {
                if (cache_.size() >= capacity_)
                    evict_lru_locked();

                node = new Node(key, value);
                append_to_back(node);
                cache_[key] = node;
                return;
            }
        }

        unique_lock<mutex> node_lock(node->mtx);
        node->value = value;
        if (node->next != tail_)
            move_to_back(node, move(node_lock));
    }

    size_t size() const
    {
        lock_guard<mutex> map_lock(map_mtx_);
        return cache_.size();
    }

private:
    struct Node
    {
        int key;
        int value;
        Node *prev;
        Node *next;
        mutable mutex mtx;

        Node(int k = 0, int v = 0)
            : key(k), value(v), prev(nullptr), next(nullptr)
        {
        }
    };

    size_t capacity_;
    unordered_map<int, Node *> cache_;
    Node *head_;
    Node *tail_;
    mutable mutex map_mtx_;

    static void lock_two_nodes(Node *a, Node *b,
                               unique_lock<mutex> &lock_a,
                               unique_lock<mutex> &lock_b)
    {
        if (a == b)
        {
            lock_a = unique_lock<mutex>(a->mtx);
            return;
        }

        if (a < b)
        {
            lock_a = unique_lock<mutex>(a->mtx, defer_lock);
            lock_b = unique_lock<mutex>(b->mtx, defer_lock);
        }
        else
        {
            lock_a = unique_lock<mutex>(b->mtx, defer_lock);
            lock_b = unique_lock<mutex>(a->mtx, defer_lock);
        }
        lock(lock_a, lock_b);

        if (a > b)
            swap(lock_a, lock_b);
    }

    static void lock_three_nodes(Node *a, Node *b, Node *c,
                                 unique_lock<mutex> &lock_a,
                                 unique_lock<mutex> &lock_b,
                                 unique_lock<mutex> &lock_c)
    {
        array<pair<Node *, int>, 3> items= {{{a, 0 }, {b, 1}, {c, 2}}};
        sort(items.begin(), items.end(), [](auto &l, auto &r)
             { return l.first < r.first; });
        array<unique_lock<mutex>, 3> locks = {unique_lock<mutex>(items[0].first->mtx, defer_lock),
                                              unique_lock<mutex>(items[1].first->mtx, defer_lock),
                                              unique_lock<mutex>(items[2].first->mtx, defer_lock)};
        lock(locks[0], locks[1], locks[2]);
        for (int i = 0; i < 3; ++i)
        {
            if (items[i].second == 0)
                lock_a = move(locks[i]);
            else if (items[i].second == 1)
                lock_b = move(locks[i]);
            else
                lock_c = move(locks[i]);
        }
    }

    void detach_node(Node *node)
    {
        Node *left = node->prev;
        Node *right = node->next;
        if (!left || !right)
            return;

        unique_lock<mutex> left_lock;
        unique_lock<mutex> right_lock;
        lock_two_nodes(left, right, left_lock, right_lock);

        left->next = right;
        right->prev = left;
        node->prev = nullptr;
        node->next = nullptr;
    }

    void append_to_back(Node *node)
    {
        while (true)
        {
            Node *prev;
            {
                lock_guard<mutex> tail_guard(tail_->mtx);
                prev = tail_->prev;
            }

            if (!prev)
                prev = head_;

            unique_lock<mutex> prev_lock;
            unique_lock<mutex> tail_lock;
            lock_two_nodes(prev, tail_, prev_lock, tail_lock);

            if (tail_->prev != prev)
                continue;

            prev->next = node;
            node->prev = prev;
            node->next = tail_;
            tail_->prev = node;
            return;
        }
    }

    void move_to_back(Node *node, unique_lock<mutex> node_lock)
    {
        detach_node(node);
        append_to_back(node);
        (void)node_lock;
    }

    void evict_lru_locked()
    {
        while (true)
        {
            Node *victim;
            Node *right;
            {
                lock_guard<mutex> head_guard(head_->mtx);
                victim = head_->next;
                if (!victim || victim == tail_)
                    return;
                right = victim->next;
            }

            unique_lock<mutex> head_lock;
            unique_lock<mutex> victim_lock;
            unique_lock<mutex> right_lock;
            lock_three_nodes(head_, victim, right, head_lock, victim_lock, right_lock);

            if (head_->next != victim || victim->next != right)
                continue;

            head_->next = right;
            right->prev = head_;
            victim->prev = nullptr;
            victim->next = nullptr;
            cache_.erase(victim->key);
            delete victim;
            return;
        }
    }
};

int main()
{
    ThreadSafeLRUCache cache(3);
    cache.put(1, 10);
    cache.put(2, 20);
    cache.put(3, 30);

    int value;
    if (cache.try_get(2, value))
        cout << "Got 2 => " << value << '\n';

    cache.put(4, 40);
    if (!cache.try_get(1, value))
        cout << "1 was evicted\n";

    return 0;
}
