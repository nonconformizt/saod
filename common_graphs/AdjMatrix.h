#ifndef COMMON_GRAPHS_ADJMATRIX_H
#define COMMON_GRAPHS_ADJMATRIX_H
#include "classes.h"
#include "EdgeList.h"


class AdjMatrix : public Graph {
public:
    bool matrix[N][N] = {false};

    explicit AdjMatrix(EdgeList * edgeList);

    void print() override;

};


#endif //COMMON_GRAPHS_ADJMATRIX_H
