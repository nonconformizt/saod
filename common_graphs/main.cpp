#include <iostream>
#include "classes.h"
#include "EdgeList.h"
#include "AdjMatrix.h"
#include "IncMatrix.h"


int main() {

    // сформируем вручную граф на основе списка рёбер

    Node *nodes[N];
    for (int i = 0; i < N; i++)
        nodes[i] = new Node(i);

    auto edgeList = new EdgeList();

    edgeList->edges[0].emplace_back(Edge(nodes[0], nodes[1]));
    edgeList->edges[1].emplace_back(Edge(nodes[1], nodes[2]));
    edgeList->edges[1].emplace_back(Edge(nodes[1], nodes[3]));
    edgeList->edges[2].emplace_back(Edge(nodes[2], nodes[3]));
    edgeList->edges[3].emplace_back(Edge(nodes[3], nodes[4]));
    edgeList->edges[4].emplace_back(Edge(nodes[4], nodes[0]));
    edgeList->edges[4].emplace_back(Edge(nodes[4], nodes[1]));

    edgeList->print();

    /*
    auto adjMatrix = new AdjMatrix(edgeList);
    adjMatrix->print();

    auto incMatrix = new IncMatrix(edgeList);
    incMatrix->print();

    auto edgeL2 = new EdgeList(incMatrix);
    edgeL2->print();
    */

    return 0;
}
