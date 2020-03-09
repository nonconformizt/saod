#include <iostream>
#include <random>

#define MAX_PRIORITY 10000


class TreapNode {
public:

    int key, priority;
    TreapNode *left, *right;

    TreapNode(int key, int priority)
    {
        this->key = key;
        this->priority = priority;
        this->left = this->right = nullptr;
    }

};


class Treap {

private: 
    TreapNode * root;

    std::mt19937 * rng;
    std::uniform_int_distribution<std::mt19937::result_type> * rnd_distr;

    TreapNode * _search (TreapNode * root, int key);
    TreapNode * _insert (TreapNode * root, int key);
    TreapNode * _remove (TreapNode * root, int key);
    TreapNode * rightRotate (TreapNode * root);
    TreapNode * leftRotate (TreapNode * root);
    void _inorder (TreapNode * root);

public: 
    Treap()
    {
        root = nullptr;

        // set up random
        std::random_device dev;
        rng = new std::mt19937(dev());
        rnd_distr = new std::uniform_int_distribution<std::mt19937::result_type>(1, MAX_PRIORITY);
    }

    ~Treap();

    TreapNode * search (int key);
    void insert (int key);
    void remove (int key);
    void inorder ();
};


TreapNode * Treap::search (int key)
{
    return _search(root, key);
}

TreapNode * Treap::_search (TreapNode * root, int key)
{
    if (root == nullptr || root->key == key)
        return root;

    if (key < root->key)
        return _search(root->left, key);
    else 
        return _search(root->right, key);
}

void Treap::insert (int key)
{
    root = _insert(root, key);
}

TreapNode * Treap::_insert (TreapNode * root, int key)
{
    if (root == nullptr)
        return new TreapNode(key, (*rnd_distr)(*rng));

    if (key < root->key) {
        root->left = _insert(root->left, key);

        if (root->left->priority > root->priority)
            root = rightRotate(root);
    }
    else {
        root->right = _insert(root->right, key);

        if (root->right->priority > root->priority)
            root = leftRotate(root);
    }

    return root;
}

TreapNode * Treap::rightRotate (TreapNode * y)
{
    TreapNode * x = y->left;
    TreapNode * T2 = x->right;

    x->right = y;
    y->left = T2;
    
    return x;
}

TreapNode * Treap::leftRotate (TreapNode * y)
{
    TreapNode * x = y->right;
    TreapNode * T2 = x->left;

    x->left = y;
    y->right = T2;
    
    return x;
}

void Treap::remove (int key)
{
    root = _remove (root, key);
}

TreapNode * Treap::_remove (TreapNode * root, int key)
{
    if (root == nullptr)
        return root;

    if (key < root->key)
        root->left = _remove(root->left, key);
    else if (key > root->key)
        root->right = _remove(root->right, key);

    // key is at root

    else if (root->left == nullptr) {
        TreapNode * tmp = root->right;
        delete root;
        root = tmp;
    }

    else if (root->right == nullptr) {
        TreapNode * tmp = root->left;
        delete root;
        root = tmp;
    }

    else if (root->left->priority < root->right->priority) {
        root = leftRotate(root);
        root->left = _remove(root->left, key);
    }
    
    else {
        root = rightRotate(root);
        root->right = _remove(root->right, key);
    }

    return root;

}

void Treap::inorder ()
{
    _inorder(root);
}

void Treap::_inorder(TreapNode * root)
{
    if (root == nullptr)
        return;
    _inorder(root->left);
    std::cout << root->key << "(" << root->priority << "); ";
    _inorder(root->right);
}
