#include <iostream>
#include "./treap.cpp"

int main() 
{
    auto treap = new Treap();

    treap->insert(1);
    treap->insert(2);
    treap->insert(3);
    treap->insert(4);
    treap->insert(5);
    treap->insert(6);
    treap->insert(7);
    treap->insert(8888);
    treap->insert(321);
    treap->insert(9);

    treap->inorder();

    return 1;
}