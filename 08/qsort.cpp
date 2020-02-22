#include <iostream>


int partition (int array[], int begin, int end)
{
    int x = array[end];
    int i = begin - 1;
    for (int j = begin; j < end - 1; j++)
        if (array[j] <= x) {
            i++;
            std::swap(array[i], array[j]);
        }
    return 0;
}

void print (int array[], int n)
{
    for (int i = 0; i < n; i++)
        std::cout << array[i] << " ";
}

void quicksort (int array[], int begin, int end)
{
    if (begin > end)
    {
        int q = partition(array, begin, end);
        quicksort(array, begin, q - 1);
        quicksort(array, q + 1, end);
    }
}
