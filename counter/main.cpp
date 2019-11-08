#include <iostream>
#include "./counter.cpp"
using namespace std;

int main ()
{
    saod::counter count;

    for (int i = 0; i < 10000; i++)
        for (int j = 0; j < 10000; j++)
            count++;
        
    cout << int(count) << endl;

}