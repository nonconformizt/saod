#include <iostream>
#include "./skip.cpp"


int main()
{
    auto list = new SkipList();

    list->insert(3);
    list->insert(6);
    list->insert(17);
    list->insert(9);
    list->insert(22);
    list->insert(231);
    list->insert(24);
    list->insert(237);
    list->insert(129);
    list->insert(12);

    list->print();

    auto x = list->search(237);

    cout << "Found element: " << x->key << endl;

    return 0;
}
