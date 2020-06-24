#ifndef COMMON_GRAPHS_ADJMATRIX_H
#define COMMON_GRAPHS_ADJMATRIX_H
#include "classes.h"
#include "EdgeList.h"
#include "IncMatrix.h"
#include "AdjStruct.h"


class AdjMatrix : public Graph {
public:
    bool matrix[N][N] = {false};

    explicit AdjMatrix(EdgeList * base);
    explicit AdjMatrix(IncMatrix * base);
    explicit AdjMatrix(AdjStruct * base);

    void print() override;

};


#endif //COMMON_GRAPHS_ADJMATRIX_H
