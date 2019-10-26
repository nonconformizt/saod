#ifndef STACK
#define STACK

#include <iostream>

namespace saod
{

// ==================== //


class stackNode
{
public:
    int data;
    stackNode * next = nullptr;

    stackNode(int d) { data = d; };
};


// ==================== //


class stack
{
private:
    stackNode * root = nullptr;
    uint32_t size = 0;

public:
    stack() {};
    void push(int d);
    int pop();
    void print();
    bool isEmpty() { return size == 0; }
};


void stack::push(int d)
{
    size++;
    auto node = new stackNode(d);

    if (root == nullptr) {
        root = node;
    }
    else {
        node->next = root;
        root = node;
    }
}


int stack::pop()
{
    if (root == nullptr)
        throw "Stack is empty!\n";

    size--;
    int res = root->data;
    auto tmp = root->next;
    delete root;
    root = tmp;
    return res;
}


void stack::print()
{
    auto ptr = root;

    while (ptr != nullptr)
    {
        std::cout << ptr->data << " ";
        ptr = ptr->next;
    }
    std::cout << std::endl;
}





} // namespace saod

#endif