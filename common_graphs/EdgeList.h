#ifndef COMMON_GRAPHS_EDGELIST_H
#define COMMON_GRAPHS_EDGELIST_H
#include "classes.h"
#include "AdjMatrix.h"
#include "IncMatrix.h"


class EdgeList : public Graph {
public:
    std::list<Edge> edges[N];

    EdgeList() = default;
    explicit EdgeList(AdjMatrix * base);
    explicit EdgeList(IncMatrix * base);

    void print() override;

};




#endif //COMMON_GRAPHS_EDGELIST_H
