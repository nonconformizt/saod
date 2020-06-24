#ifndef COMMON_GRAPHS_CLASSES_H
#define COMMON_GRAPHS_CLASSES_H

#include <iostream>
#include <list>

// число вершин
#define N 5


struct Node {
    int i; // index of node
    explicit Node(int i) { this->i = i; }
};

struct Edge {
    Node *from,
         *to;

    Edge(Node *f, Node *t) {
        from = f;
        to = t;
    }

    void print() const {
        printf("%d ==> %d\n", from->i, to->i);
    }
};


class Graph {
    virtual void print() = 0;
};

class AdjMatrix;
class IncMatrix;
class EdgeList;
class AdjStruct;




#endif //COMMON_GRAPHS_CLASSES_H
