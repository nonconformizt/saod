#include "AdjStruct.h"

AdjStruct::AdjStruct(EdgeList *base)
{
    for (std::list<Edge> & list: base->edges)
        for (Edge & e: list)
            adj[e.from->i].emplace_back(e.to);
}

AdjStruct::AdjStruct(AdjMatrix *base)
{
    Node * nodes[N];
    for (int i = 0; i < N; i++)
        nodes[i] = new Node(i);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (base->matrix[i][j])
                adj[i].emplace_back(nodes[j]);
}

AdjStruct::AdjStruct(IncMatrix *base)
{
    Node * nodes[N];
    for (int i = 0; i < N; i++)
        nodes[i] = new Node(i);

    int beg;
    Node *end;
    for (int j = 0; j < base->E; j++) {
        for (int i = 0; i < N; i++) {
            if (base->matrix[i][j] == -1)
                beg = i;
            else if (base->matrix[i][j] == 1)
                end = nodes[i];
        }
        adj[beg].emplace_back(end);
    }

}

void AdjStruct::print()
{
    std::cout << "========================\n";
    std::cout << "==Структура смежности:==\n";
    for(int i = 0; i < N; i++) {
        std::cout << "\nУзел : " << i << "; Соседи: ";
        for (Node *node: adj[i]) {
            std::cout << node->i << " ";
        }
    }
    std::cout << "\n";
}
