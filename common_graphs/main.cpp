#include <iostream>
#include "classes.h"
#include "EdgeList.h"
#include "AdjMatrix.h"
#include "AdjStruct.h"
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

    // тестируем создание различных типов графов на основе других

    // Матрица инцидентности на основе Списка граней
    auto incMatrix = new IncMatrix(edgeList);
    incMatrix->print();

    // Структура смежности на основе Матрицы инцидентности
    auto adjStruct = new AdjStruct(incMatrix);
    adjStruct->print();

    // Матрица смежности на основе Структуры смежности
    auto adjMatrix = new AdjMatrix(adjStruct);
    adjMatrix->print();

    // Список граней на основе Матрицы смежности
    auto edgeList2 = new EdgeList(adjStruct);
    edgeList2->print();

    // и т.д.

    return 0;
}
