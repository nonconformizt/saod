#ifndef AVL_TREE
#define AVL_TREE
#include <iostream>

namespace saod
{


class TreeNode {

public: 
    TreeNode(int d);
    int data;
    int height;
    TreeNode * left, 
             * right;

    void print();

};


TreeNode::TreeNode(int d)
{
    left = right = nullptr;
    height = 1;
    data = d;
}


void TreeNode::print() 
{
    std::cout << data << " ";
    if (left != nullptr)
        left->print();
    if (right != nullptr)
        right->print();
}


/**********************************************************/


class Tree {

private: 
    TreeNode * root = nullptr;
    int _max(int a, int b);
    int height(TreeNode * n);
    int getBalance(TreeNode * n);

    TreeNode * rightRotate(TreeNode * y);
    TreeNode * leftRotate(TreeNode * x);
    // внутренний алгоритм вставки
    TreeNode * _insert(TreeNode * node, int data); 

public: 
    void insert(int data) { 
        // std::cout << data;
        root = _insert(root, data); 
    }
    void print() { root->print(); }

};



TreeNode * Tree::_insert(TreeNode * node, int data)
{
    /* 1. Обычная вставка элемента в бинарное дерево поиска */

    if (node == nullptr)
        return new TreeNode(data);

    if (data < node->data)
        node->left = _insert(node->left, data);
    else if (data > node->data)
        node->right = _insert(node->right, data);
    else  // одиинаковые узлы не допускаются
        return node; // ???

    /* 2. Обновить высоту этого предка  */

    node->height = 1 + _max(height(node->left), height(node->right));

    /* 3. Получить значение баланса чтобы проверить, не нарушился ли баланс */
    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);
    
    // Right Right Case
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}


int Tree::height(TreeNode * n)
{
    if (n == nullptr)
        return 0;
    return n->height;
}


int Tree::_max(int a, int b)
{
    return (a > b) ? a : b;
}


TreeNode * Tree::rightRotate(TreeNode * y)
{
    TreeNode * x = y->left;
    TreeNode * T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = _max(height(y->left), height(y->right)) + 1;
    x->height = _max(height(x->left), height(x->right)) + 1;

    return x;
}


TreeNode * Tree::leftRotate(TreeNode * x)
{
    TreeNode * y = x->right;
    TreeNode * T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = _max(height(x->left), height(x->right)) + 1;
    y->height = _max(height(y->left), height(y->right)) + 1;

    return y;
}


int Tree::getBalance(TreeNode * n)
{
    if (n == nullptr)
        return 0;
    return height(n->left) - height(n->right);
}







} // namespace saod

#endif // AVL_TREE