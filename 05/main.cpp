#include <iostream>
#include "parser.cpp"
using namespace std;


int main ()
{
    saod::Parser parser;

    parser.parse("(1+2)*7");
    
}