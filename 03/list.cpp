#ifndef LIST
#define LIST

#include <iostream>

namespace saod
{

// ==================== //


class listNode
{
public:
    int data;
    listNode * next = nullptr;

    listNode(int d) { data = d; };
};


// ==================== //


class list
{
private:
    listNode * root = nullptr;
    static void order(uint32_t * a, uint32_t * b);
public:
    list() {};
    void push(int d);
    int pop();
    void swap(uint32_t m, uint32_t n);
    void print();
};


void list::push(int d)
{
    auto node = new listNode(d);

    if (root == nullptr) {
        root = node;
    }
    else {
        node->next = root;
        root = node;
    }
}


int list::pop()
{
    int res = root->data;
    auto tmp = root->next;
    delete root;
    root = tmp;
    return res;
}


void list::swap(uint32_t m, uint32_t n)
{
    if (m == n)
        return;

    order(&m, &n);

    listNode * m_node = nullptr,
             * m_prev = nullptr, 
             * n_node = nullptr, 
             * n_prev = nullptr, 
             * tmp;

    // найти элементы, с которыми будем работать,
    // и предшествующие им
    uint32_t i = 0;
    tmp = root;

    while (tmp != nullptr) 
    {
        if (i == m - 1) {
            m_prev = tmp;
            m_node = tmp->next;
        }
        if (i == n - 1) {
            n_prev = tmp;
            n_node = tmp->next;
        }
        i++;
        tmp = tmp->next;
    }

    if (m == 0)
        m_node = root;

    if (n_node == nullptr || m_node == nullptr)
        throw "Error: node not found!\n";


    // 
    // частный случай
    //
    if (n - m == 1) // соседние элементы
    {
        m_node->next = n_node->next; // 1
        n_node->next = m_node;       // 2
        // элемент перед m отсутствует, если m - вершина.
        if (m_prev)
            m_prev->next = n_node;   // 3
    }
    //
    // общий случай
    //
    else 
    {
        tmp = m_node->next;
        m_node->next = n_node->next; // 1
        n_node->next = tmp;          // 2

        n_prev->next = m_node;       // 3
        // элемент перед m отсутствует, если m - вершина.
        if (m_prev)
            m_prev->next = n_node;   // 4
    }

    // переназначить вершину
    if (m_node == root)
        root = n_node;

}


void list::print()
{
    auto ptr = root;

    while (ptr != nullptr)
    {
        std::cout << ptr->data << " ";
        ptr = ptr->next;
    }
    std::cout << std::endl;
}


// отсортировать два числа по возрастанию
// Антон, я знаю, что ты посоветуешь написать макрос
// но мне лень
// и еще ты спросишь, почему комментарии on russian
void list::order(uint32_t * a, uint32_t * b)
{
    if (*a > *b) {
        int tmp = *b;
        *b = *a;
        *a = tmp;
    }
}




} // namespace saod

#endif