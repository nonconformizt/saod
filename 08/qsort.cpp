#include <iostream>
#ifndef QSORT
#define QSORT

namespace saod
{

void quicksort (int array[], int begin, int end);
int partition (int array[], int begin, int end);
void print (int array[], int n);


void quicksort (int array[], int begin, int end)
{
    if (begin < end)
    {
        int q = partition(array, begin, end);
        quicksort(array, begin, q - 1);
        quicksort(array, q + 1, end);
    }
}

int partition (int array[], int begin, int end)
{
    int x = array[end];
    int i = begin - 1;
    for (int j = begin; j <= end - 1; j++)
        if (array[j] <= x) {
            i++;
            std::swap(array[i], array[j]);
        }
    std::swap(array[i + 1], array[end]);
    return i + 1;
}



} // namespace saod
#endif