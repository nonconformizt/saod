#include <iostream>
using namespace std;

/*
*   Быстрый алгоритм, вычисляет по формуле
*
*   Выполняется за время O(m/2)
*   (в среднем случае за гораздо меньшее время)
*
*/


int main()
{
    int n; // максимальное число на бочонке
    int m; // сумма чисел на двух бочонках
    int count = 0; // счетчик найденных пар
    int first, last;


    cout << "Введите n: ";
    cin >> n;
    cout << "Введите m: ";
    cin >> m;


    
    if (n < m / 2) // целоч. деление здесь подходит 
        // нет решений
        count = 0;
    else 
    {
        if (n >= m) { // в этом случае максимум решений
            count = m + 1;

            first = 0;
            last = m;
        }
        else {
            count = 2*n - m + 1;

            first = m - n;
            last = n;
        }
        

        while (first < last)
        {
            cout << "(" << first << "; " << last << ")\n";
            cout << "(" << last << "; " << first << ")\n";
            first++;
            last--;
        }

        if (first == last) 
            // эта строчка достижима только в случае четного m
            cout << "(" << first << "; " << first << ")\n";            

    }


    cout << "Найдено пар: " << count << endl;

}