#include "IncMatrix.h"

IncMatrix::IncMatrix(AdjMatrix *base)
{
    matrix = new int* [N];
    E = 0;
    // count number of edges
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (base->matrix[i][j])
                E++;

    for (int i = 0; i < N; i++)
        matrix[i] = new int[E];

    int currEdge = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            if (base->matrix[i][j])
            {
                matrix[i][currEdge] = -1; // грань начинается
                matrix[j][currEdge] = 1;  // грань заканчивается
                currEdge++;
            }
    }
}

IncMatrix::IncMatrix(EdgeList *base)
{
    matrix = new int* [N];
    E = 0;
    // count number of edges
    for (std::list<Edge> & list : base->edges)
        E += list.size();

    for (int i = 0; i < N; i++)
        matrix[i] = new int[E];

    int currEdge = 0;
    for (std::list<Edge> & list : base->edges) {
        for (Edge & e : list) {
            matrix[e.from->i][currEdge] = -1;
            matrix[e.to->i][currEdge] = 1;
            currEdge++;
        }
    }

}


void IncMatrix::print()
{
    std::cout << "==========================\n";
    std::cout << "==Матрица инцидентности:==\n   ";
    for (int i = 0; i < E; i++)
        std::cout << "\te" << i;
    std::cout << "\n   ";
    for (int i = 0; i < E; i++)
        std::cout << "----";
    std:: cout << "\n";
    for (int i = 0; i < N; i++) {
        std::cout << i << " |";
        for (int j = 0; j < E; j++)
            std::cout << "\t" << matrix[i][j];
        std::cout << std::endl;
    }
}

