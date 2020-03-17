#include <iostream>
#include "./skip.cpp"


int main()
{
    auto list = new SkipList();

    list->insert(3);
    list->insert(6);
    list->insert(17);
    list->insert(9);
    list->insert(25);
    list->insert(7);
    list->insert(19);
    list->insert(-19);
    list->insert(1);
    list->insert(-12);
    list->insert(100);
    list->insert(21);
    list->insert(22);
    list->insert(23);
    list->insert(24);
    list->insert(27);
    list->insert(29);
    list->insert(12);

    list->print();

    return 0;
}
