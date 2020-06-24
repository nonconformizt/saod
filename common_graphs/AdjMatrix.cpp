#include "AdjMatrix.h"


AdjMatrix::AdjMatrix(EdgeList *edgeList)
{
    for (std::list<Edge> & list: edgeList->edges)
        for (Edge & e: list)
            matrix[ e.from->i ][ e.to->i ] = true;
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