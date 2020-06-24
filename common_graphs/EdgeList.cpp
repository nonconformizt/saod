#include "EdgeList.h"

EdgeList::EdgeList(AdjMatrix *base)
{
    Node * nodes[N];
    for (int i = 0; i < N; i++)
        nodes[i] = new Node(i);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (base->matrix[i][j])
                edges[i].emplace_back(Edge(nodes[i], nodes[j]));
}

EdgeList::EdgeList(IncMatrix *base)
{
    Node * nodes[N];
    for (int i = 0; i < N; i++)
        nodes[i] = new Node(i);

    Node *beg, *end;
    for (int j = 0; j < base->E; j++) {
        for (int i = 0; i < N; i++) {
            // найти начало и конец грани
            if (base->matrix[i][j] == -1)
                beg = nodes[i];
            else if (base->matrix[i][j] == 1)
                end = nodes[i];
        }
        if (beg && end)
            edges[beg->i].emplace_back(Edge(beg, end));
    }

}

void EdgeList::print()
{
    std::cout << "=================\n";
    std::cout << "==Список рёбер:==\n";
    for (int i = 0; i < N; i++) {
        std::cout << "Вершина " << i << std::endl;
        for (Edge & e : edges[i])
            e.print();
    }
}

