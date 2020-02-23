#include <iostream>
#ifndef RADIX
#define RADIX

namespace saod
{

void radixsort(int a[], int n);
void sortDigits(int a[], int n, int exp);
int getMax(int a[], int n);


int getMax(int a[], int n)
{
  int max = a[0];
  for (int x = 1; x < n; x++)
    if (a[x] > max)
        max = a[x];
  return max;
}

// Function to do counting sort according to significant digits repesented by
// exp (where exp is 10^i).
void sortDigits(int a[], int n, int exp)
{  
  int result[n], i, digit, count[10] = {0};

  // Counting occurence of digits
  for (i = 0; i < n; i++)
    count[(a[i] / exp) % 10]++;

  for (i = 1; i < 10; i++)
    count[i] += count[i-1];

  for (i = n - 1; i >= 0; i--)
  {
    digit = (a[i] / exp) % 10;
    result[ count[digit] - 1 ] = a[i];
    count[digit]--;
  }

  for (i = 0; i < n; i++)
    a[i] = result[i];
}

void radixsort(int a[], int n)
{
  int exp, i;
  i = getMax(a, n);
  for (exp = 1; i / exp > 0; exp *= 10)
    sortDigits(a, n, exp);
}



} // namespace saod

#endif