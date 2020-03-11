#include <iostream>
#include "./treap.cpp"

int main() 
{
    auto treap = new Treap();

    for (int i = 1; i < 1000; i++)
        treap->insert(i);

    auto finger = treap->search(20);

    auto needle = treap->fingerSearch(15, finger);

    std::cout << "Result: " <<  needle->key << "\n";

    return 1;
}