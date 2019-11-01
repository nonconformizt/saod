#ifndef BRACKETS
#define BRACKETS

#include <iostream>
#include "./stack.cpp"

namespace saod
{



// возвращает массив 
int * buildBracketsSequence(int pairs[][2], int pairs_n, int * seq_len)
{
    // найдем максимальный индекс 
    int max = -1;
    for (int i = 0; i < pairs_n; i++) 
        if (pairs[i][1] > max)
            max = pairs[i][1];
    
    // вычислим минимальное количество строк
    int lines_n = max + 1;
    (*seq_len) = lines_n;

    int * seq = new int[lines_n];

    // обнулить массив
    for (int i = 0; i < lines_n; i++) seq[i] = 0;

    for (int i = 0; i < pairs_n; i++)
    {
        seq[pairs[i][0]] = (i + 1); // означает открывающуюся скобку
        seq[pairs[i][1]] = - (i + 1); // означает закрывающуюся скобку
    }

    return seq;
}


bool validateBrackets(int * seq, int seq_len)
{
    auto stack = saod::stack();
    uint32_t tmp;

    for (int i = 0; i < seq_len; i++)
    {
        if (seq[i] > 0)
            stack.push(seq[i]);
        else if (seq[i] < 0) 
        {
            try {
                tmp = stack.pop();
                if (tmp != abs(seq[i]))
                    return false;
            }
            catch (std::exception e) {
                // стэк пустой в этом случае
                return false;
            }
        }
    }

    return stack.isEmpty(); // если стек стал пустым, все прошло хорошо
}





}

#endif