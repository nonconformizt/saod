#include <iostream>
#include <random>

#define MAX_PRIORITY 10000


class TreapNode {
public:

    int key, priority;
    TreapNode *left, *right, *parent;

    TreapNode(TreapNode * parent, int key, int priority)
    {
        this->parent = parent;
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
    TreapNode * _insert (TreapNode * root, TreapNode * parent, int key);
    TreapNode * _remove (TreapNode * root, int key);
    TreapNode * rightRotate (TreapNode * root);
    TreapNode * leftRotate (TreapNode * root);
    void _inorder (TreapNode * root);

public: 
    Treap()
    {
        root = nullptr;

        // set up random
        using namespace std;
        random_device dev;
        rng = new mt19937(dev());
        rnd_distr = new uniform_int_distribution<mt19937::result_type>(1, MAX_PRIORITY);
    }

    ~Treap();

    TreapNode * search (int key);
    TreapNode * fingerSearch (int key, TreapNode * finger);
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
    root = _insert(root, nullptr, key);
}

TreapNode * Treap::_insert (TreapNode * root, TreapNode * parent, int key)
{
    if (root == nullptr)
        return new TreapNode(parent, key, (*rnd_distr)(*rng));

    if (key < root->key) {
        root->left = _insert(root->left, root, key);

        if (root->left->priority > root->priority)
            root = rightRotate(root);
    }
    else {
        root->right = _insert(root->right, root, key);

        if (root->right->priority > root->priority)
            root = leftRotate(root);
    }

    return root;
}

TreapNode * Treap::rightRotate (TreapNode * y)
{
    TreapNode * x = y->left;
    TreapNode * T2 = x->right;
    TreapNode * ancestor = y->parent;

    x->right = y;
    x->parent = ancestor;
    y->left = T2;
    y->parent = x;
    if (T2 != nullptr)
        T2->parent = y;
    
    return x;
}

TreapNode * Treap::leftRotate (TreapNode * y)
{
    TreapNode * x = y->right;
    TreapNode * T2 = x->left;
    TreapNode * ancestor = y->parent;

    x->left = y;
    x->parent = ancestor;
    y->parent = x;  
    y->right = T2;
    if (T2 != nullptr)
        T2->parent = y;
    
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

TreapNode * Treap::fingerSearch (int needle, TreapNode * finger)
{
    std::cout << "Starting finger search\n";
    std::cout << "Finger = " << finger->key << "\n";

    // start advancing to the root

    TreapNode * v = finger->parent;
    TreapNode * lastNode = nullptr;
    TreapNode * LCA = nullptr;

    if (needle > finger->key) {

        while (true)
        {
            if (v == nullptr) {// root reached
                std::cout << "Root reached!\n";
                LCA = root; break;
            }
                
            std::cout << "Node " << v->key << "\n";

            // case 1
            if (finger->key >= v->key) // x is in the right subtree
                                    // and v cannot be desired ancestor
                v = v->parent; // continue advancing
            // case 2
            else if (finger->key < v->key && v->key <= needle)
            {
                // finger is in the left subtree of v and desired node 
                // is v or its ancestor
                lastNode = v;
                v = v->parent;
            }
            // case 3
            else if (needle < v->key)
            {
                // LCA found!
                LCA = lastNode;
                break;
            }
        }

    } else {

        while (true)
        {
            if (v == nullptr) { // root reached
                std::cout << "Root reached!\n";
                LCA = root; break;
            }
                
            std::cout << "Node " << v->key << "\n";

            // case 1
            if (finger->key <= v->key) // x is in the right subtree
                                       // and v cannot be desired ancestor
                v = v->parent; // continue advancing
            // case 2
            else if (finger->key > v->key && v->key >= needle)
            {
                // finger is in the left subtree of v and desired node 
                // is v or its ancestor
                lastNode = v;
                v = v->parent;
            }
            // case 3
            else if (needle > v->key)
            {
                // LCA found!
                LCA = lastNode;
                break;
            }
        }

    }

    std::cout << "LCA found: " << LCA->key << "\n";

    // using common treap search 
    // considering LCA as root

    return _search (LCA, needle);

}
