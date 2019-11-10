#include <iostream>
#include "./math_tree.cpp"
using namespace std;


int main ()
{
    saod::Tree tree;

    tree.fill();

    std::cout << tree.solve() << std::endl;
}