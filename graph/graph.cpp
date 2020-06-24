#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

class Map {

private:
    int cityCounter;
    vector < list<pair<int, int>>> roads;     // дороги [<куда, расстояние>]
    map <string, int> cities; // соответствие номера города его имени

    int getCityID(string name);

public: 
    Map() {
        cityCounter = 0;
    }

    void addCity(string name);
    void addRoad(string from, string to, int dist);
    void deleteRoad(string from, string to);

};

void Map::addCity(string name) 
{
    cityCounter++;
    cities.insert(pair<string, int>(name, cityCounter));
    roads.resize(cityCounter);
}

void Map::addRoad(string from, string to, int dist)
{
    /**
     * Найти ID городов
     */

    int fromID = getCityID(from);
    int toID = getCityID(to);

    if (fromID == toID) // дорога должна идти из одного города В ДРУГОЙ
        throw 500;

    cout << "from: " << fromID << " to: " << toID;

    /**
     * Соединить города
     * 
     * Так как по дорогам можно ездить в 2 стороны, 
     * то мы создаем 2 дороги: в одну сторону, и в другую
     */

    roads[toID].push_back(pair<int, int>(fromID, dist));
    roads[fromID].push_back(pair<int, int>(toID, dist));

}


void Map::deleteRoad(string from, string to)
{
    /**
     * Найти ID городов
     */

    int fromID = getCityID(from);
    int toID = getCityID(to);
    
    /**
     * Удалить дороги
     */

    list<pair<int, int>>::iterator it;
    for (it = roads[fromID].begin(); it != roads[fromID].end(); ++it )
        if (it->first == toID) {
            roads[fromID].erase(it);
            break;
        }

    for (it = roads[toID].begin(); it != roads[toID].end(); ++it )
        if (it->first == fromID) {
            roads[toID].erase(it);
            break;
        }


}

int Map::getCityID(string name)
{
    map<string, int>::iterator it;

    it = cities.find(name);
    if (it == cities.end())
        throw 404;

    return it->second;

}
