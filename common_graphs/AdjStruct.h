#ifndef COMMON_GRAPHS_ADJSTRUCT_H
#define COMMON_GRAPHS_ADJSTRUCT_H
#include "classes.h"
#include "EdgeList.h"
#include "IncMatrix.h"
#include "AdjMatrix.h"

class AdjStruct : public Graph {
public:
    std::list<Node*> adj[N];

    explicit AdjStruct(EdgeList * base);
    explicit AdjStruct(IncMatrix * base);
    explicit AdjStruct(AdjMatrix * base);

    void print() override;
};


#endif //COMMON_GRAPHS_ADJSTRUCT_H
