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
        TreapNode * _insert (TreapNode * root, TreapNode * node);


    public: 
        Treap()
        {
            root = nullptr;

            // set up random
            std::random_device dev;
            rng = new std::mt19937(dev());
            rnd_distr = new std::uniform_int_distribution<std::mt19937::result_type>(1, MAX_PRIORITY);
            // (*rnd_distr)(*rng)
        }

        ~Treap();

        TreapNode * insert (int key);
        TreapNode * search (int key);
        void remove (int key);

        
};


TreapNode * Treap::search (int key)
{
    return _search(root, key);
}


TreapNode * _search (TreapNode * root, int key)
{
    if (root == nullptr || root->key == key)
        return root;

    if (key < root->key)
        return _search(root->left, key);
    else 
        return _search(root->right, key);
}


TreapNode * Treap::insert (int key)
{
    auto node = new TreapNode(key, (*rnd_distr)(*rng));

}


TreapNode * Treap::_insert (TreapNode * root, TreapNode * node)
{

}
