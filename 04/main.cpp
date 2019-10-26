#include <iostream>
#include "./stack.cpp"
using namespace std;

// возвращает массив 
int * buildBracketsSequence(int pairs[][2], int pairs_n, int * seq_len)
{
    // найдем максимальный индекс 
    int max = -1;
    for (int i = 0; i < pairs_n; i++) 
        if (pairs[i][1] > max)
            max = pairs[i][1];
    
    int * seq = new int[max + 1];
    (*seq_len) = max + 1;

    // обнулить массив
    for (int i = 0; i < max + 1; i++) seq[i] = 0;

    for (int i = 0; i < pairs_n; i++)
    {
        seq[pairs[i][0]] = i; // означает открывающуюся скобку
        seq[pairs[i][1]] = -i; // означает закрывающуюся скобку
    }

    for (int i = 0; i < max + 1; i++) cout << seq[i] << " ";
    cout << endl;

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
        else if (seq[i] < 0) {
            try {
                tmp = stack.pop();
                if (tmp != abs(seq[i]))
                    return false;
            }
            catch (exception e) {
                // стэк пустой в этом случае
                return false;
            }
        }
    }

    if (stack.isEmpty())
        return true;
    else 
        return false;
}


int main()
{
    int pairs_n = 4;
    int pairs [][2] = {
        {4, 30},
        {5, 15},
        {6, 10},
        {21, 28}
    };

    int seq_len;
    int * seq = buildBracketsSequence(pairs, pairs_n, &seq_len);

    if (validateBrackets(seq, seq_len))
        cout << "Скобки расставлены правильно \n";
    else 
        cout << "Скобки расставлены НЕПРАВИЛЬНО \n";

    return 0;
}