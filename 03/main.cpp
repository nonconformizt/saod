#include <iostream>
#include "./list.cpp"
using namespace std;

int main()
{
    auto mylist =  saod::list();

    mylist.push(77);
    mylist.push(63);
    mylist.push(83);
    mylist.push(11);
    mylist.push(39);
    mylist.push(12);
    mylist.push(53);
    mylist.push(38);

    mylist.print();

    mylist.swap(0, 1);

    mylist.print();


    return 0;
}