#ifndef STACK
#define STACK

#include <iostream>

namespace saod
{

// ==================== //


class StackNode
{
public:
    char data;
    StackNode * next = nullptr;

    StackNode(char d) { data = d; };
};


// ==================== //


class Stack
{

private:
    StackNode * root = nullptr;
    uint32_t size = 0;

public:
    Stack() {};
    void push(char d);
    char pop();
    char top() { return (root == nullptr) ? 0 : root->data; }
    bool isEmpty() { return size == 0; }
    bool notEmpty() { return size != 0; }
    void print();

};


void Stack::push(char d)
{
    auto node = new StackNode(d);

    if (root == nullptr) {
        root = node;
    }
    else {
        node->next = root;
        root = node;
    }

    size++;
}


char Stack::pop()
{
    if (root == nullptr)
        throw "Stack is empty!\n";

    char res = root->data;
    auto tmp = root->next;
    delete root;
    root = tmp;
    
    size--;
    return res;
}


void Stack::print()
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

#endif // STACK 