#include <iostream>
#include "./qsort.cpp"
using namespace std;



void print (int array[], int n) 
{ for (int i = 0; i < n; i++) cout << array[i] << " "; }

int main()
{
    int test[] = {2, 8, 7, 1, 3, 5, 6, 4};
    int n = sizeof(test) / sizeof(test[0]);

    cout << "Sorted: \n";
    saod::quicksort(test, 0, n - 1);
    print(test, n);

}

