#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

class Map {

private:
    int N; // число физических величин
    // массив, содержащий списки смежности для каждой величины
    // каждоe хранимое ребро (физ. эффект), имеет название
    list<pair<int, string>> * adj; 

    void recursiveFindChains(string, int, int, vector<bool> &, vector<pair<int, string>> &);


public:
    Map (int N)
    {
        this->N = N;
        adj = new list<pair<int, string>>[N];
    }

    void addEffect(int q1, string name, int q2)
    {
        adj[q1].push_back(make_pair(q2, name));
    }

    void findChains(int a, int b);
    void printChain(vector<pair<int, string>> &path);
 
};



void Map::findChains(int a, int b)
{
	vector<bool> visited(N);
    vector<pair<int, string>> path;

    recursiveFindChains("", a, b, visited, path);
}

void Map::recursiveFindChains(string effect, int src, int dest, vector<bool> &visited, vector<pair<int, string>> &path)
{
    visited[src] = true;

    path.push_back(make_pair(src, effect));

    if (src == dest)
        printChain(path);

    for (auto edge: adj[src])
    {
        if (!visited[edge.first])
            recursiveFindChains(edge.second, edge.first, dest, visited, path);
    }

    path.pop_back();
    visited[src] = false;
}

void Map::printChain(vector<pair<int, string>> &path)
{
    for (auto i : path)
    {
        
        if (i.second.length() > 0)
            cout << i.second << " - ";
        cout << i.first << " - ";
    }
    cout << endl;
}
