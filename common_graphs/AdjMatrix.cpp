#include "AdjMatrix.h"


AdjMatrix::AdjMatrix(EdgeList *base)
{
    for (std::list<Edge> & list: base->edges)
        for (Edge & e: list)
            matrix[ e.from->i ][ e.to->i ] = true;
}

AdjMatrix::AdjMatrix(IncMatrix *base)
{
    int beg, end;
    for (int j = 0; j < base->E; j++) {
        for (int i = 0; i < N; i++) {
            // найти начало и конец грани
            if (base->matrix[i][j] == -1)
                beg = i;
            else if (base->matrix[i][j] == 1)
                end = i;
        }

        matrix[beg][end] = true;
    }
}

AdjMatrix::AdjMatrix(AdjStruct *base)
{
    for (int i = 0; i < N; i++)
        for (Node *node : base->adj[i])
            matrix[i][node->i] = true;
}

void AdjMatrix::print()
{
    std::cout << "======================\n";
    std::cout << "==Матрица смежности:==\n   ";
    for (int i = 0; i < N; i++)
        std::cout << " " << i;
    std::cout << "\n   ";
    for (int i = 0; i < N; i++)
        std::cout << "--";
    std:: cout << "\n";
    for (int i = 0; i < N; i++) {
        std::cout << i << " |";
        for (int j = 0; j < N; j++)
            std::cout << " " << (int)matrix[i][j];
        std::cout << std::endl;
    }

}