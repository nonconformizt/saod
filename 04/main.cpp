#include <iostream>
#include "./brackets.cpp"
using namespace std;



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
    int * seq = saod::buildBracketsSequence(pairs, pairs_n, &seq_len);

    cout << "\n";
    for (int i = 0; i < seq_len; i++) 
        cout << seq[i] << " ";
    cout << "\n\n";


    if (saod::validateBrackets(seq, seq_len))
        cout << "Скобки расставлены правильно \n\n";
    else 
        cout << "Скобки расставлены НЕПРАВИЛЬНО \n\n";

    return 0;
}