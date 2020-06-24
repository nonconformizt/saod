#ifndef COMMON_GRAPHS_INCMATRIX_H
#define COMMON_GRAPHS_INCMATRIX_H
#include "classes.h"
#include "EdgeList.h"
#include "AdjMatrix.h"
#include "AdjStruct.h"


class IncMatrix : public Graph {
public:
    int ** matrix;
    int E; // number of edges

    explicit IncMatrix(AdjMatrix *base);
    explicit IncMatrix(EdgeList *base);
    explicit IncMatrix(AdjStruct *base);
    void print() override;

};


#endif //COMMON_GRAPHS_INCMATRIX_H
