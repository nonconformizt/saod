#include <iostream>
#include <cstring>
#include "./qsort.cpp"
#include "./radix.cpp"
#include "./timer.cpp"
using namespace std;

#define SIZE 1000000
#define THRESHOLD 100000


void print (int array[], int n)
{ for (int i = 0; i < n; i++) cout << array[i] << " "; cout << endl;}

int * generate () {
    int * arr = new int[SIZE];
    for (int i = 0; i < SIZE; i++) 
        arr[i] = rand() % THRESHOLD;
    return arr;
}

int main()
{
    int * arr1 = generate();
    int * arr2 = new int[SIZE];
    std::memcpy(arr2, arr1, SIZE * sizeof(int));

    // print(arr1, SIZE);
    // print(arr2, SIZE);

    saod::startTimer();
    saod::radixsort(arr1, SIZE);
    saod::endTimer();
    std::cout << "\nRadix sort: " << saod::getMicroseconds() << " microseconds\n";
    
    // print(arr1, SIZE);

    saod::startTimer();
    saod::quicksort(arr2, 0, SIZE - 1);
    saod::endTimer();
    std::cout << "\nQuick sort: " << saod::getMicroseconds() << " microseconds\n";
    
    // print(arr2, SIZE);

}

