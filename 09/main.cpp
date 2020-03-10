#include <iostream>
#include "./avl-2.cpp"


int main ()
{
    Tree avl;

    avl.insert(10);
    avl.insert(20);
    avl.insert(30);
    avl.insert(40);
    avl.insert(50);
    avl.insert(25);

    avl.print();

}
