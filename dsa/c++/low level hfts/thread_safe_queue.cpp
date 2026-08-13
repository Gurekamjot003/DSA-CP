#include <bits/stdc++.h>
using namespace std;

class Queue
{
public:
    struct Node
    {
        int data;
        atomic<Node *> next; // atomic pointer for safe producer/consumer handoff

        Node(int x) : data(x), next(nullptr) {}
    };

    Node *head;
    Node *tail;
    mutex head_mtx;
    mutex tail_mtx;

    Queue() : head(new Node(0)), tail(head) {}

    ~Queue()
    {
        while (true)
        {
            lock_guard<mutex> lock(head_mtx);
            Node *next = head->next.load();
            if (!next)
            {
                delete head;
                return;
            }
            Node *old_head = head;
            head = next;
            delete old_head;
        }
    }

    void push(int x)
    {
        Node *new_node = new Node(x);
        lock_guard<mutex> lock(tail_mtx);
        // publish the new node to the queue
        tail->next.store(new_node);
        tail = new_node;
    }

    void pop()
    {
        lock_guard<mutex> lock(head_mtx);
        Node *old_head = head;
        Node *new_head = old_head->next.load();
        if (!new_head)
            return;
        head = new_head;
        delete old_head;
    }

    int front()
    {
        lock_guard<mutex> lock(head_mtx);
        Node *first = head->next.load();
        if (!first)
            throw runtime_error("Queue is empty");
        return first->data;
    }

    bool empty()
    {
        lock_guard<mutex> lock(head_mtx);
        return head->next.load() == nullptr;
    }
};

int main()
{
}
