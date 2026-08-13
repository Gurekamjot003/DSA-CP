#include <bits/stdc++.h>
using namespace std;

class Stack
{
public:
    struct Node
    {
        int data;
        Node *next;
        Node *back;

        Node(int x) : data(x), next(nullptr), back(nullptr) {}
    };

    Node *top;
    mutex mtx;

    Stack() : top(nullptr) {}
    ~Stack()
    {
        clear();
    }

    void push(int x)
    {
        Node *new_node = new Node(x);
        lock_guard<mutex> lock(mtx);
        if (top)
        {
            top->next = new_node;
            new_node->back = top;
        }
        top = new_node;
    }

    void pop()
    {
        lock_guard<mutex> lock(mtx);
        if (!top)
            return;
        Node *temp = top;
        top = top->back;
        if (top)
        {
            top->next = nullptr;
            temp->back = nullptr;
        }
        delete temp;
    }

    int topValue()
    {
        lock_guard<mutex> lock(mtx);
        if (!top)
            throw runtime_error("Stack is empty");
        return top->data;
    }

    bool empty()
    {
        lock_guard<mutex> lock(mtx);
        return top == nullptr;
    }

private:
    void clear()
    {
        lock_guard<mutex> lock(mtx);
        while (top)
        {
            Node *temp = top;
            top = top->back;
            delete temp;
        }
    }
};

int main()
{
}