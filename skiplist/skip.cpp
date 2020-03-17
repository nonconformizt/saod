#include <bits/stdc++.h> 
#include <iostream>
using namespace std;


class SkipList {

public:
    class Node;

    SkipList();
    SkipList::Node * insert (int key);
    void print();


private:
    const int LEVELS = 3;
    const float P = 0.5f;

    Node * head;

    int randomLevel();

};


class SkipList::Node {
public:
    int key;
    Node **forward; // array 
    
    Node (int key, int level)
    {
        this->key = key;
        forward = new Node * [level+1]; 
        memset(forward, 0, sizeof(Node*) * (level+1)); 
        for (int i = 0; i <= level; i++)
            forward[i] = nullptr;
    }
};


SkipList::SkipList()
{
    head = new Node(0, LEVELS - 1);
}


SkipList::Node * SkipList::insert (int key)
{
    // begin from top level

    cout << "Inserting " << key << endl;

    int insertLevel = randomLevel();
    Node * node = new Node (key, insertLevel);
    Node * head = this->head;
    Node * next = nullptr;
    Node * tmp = nullptr;


    for (int level = LEVELS - 1; level >= 0; level--)
    {
        cout << "Inspecting level " << level << endl;

        // move right until bigger node is found OR END IS REACHED
        do {
            next = head->forward[level];
            if (next == nullptr) {
                cout << "Next key is null";
                break; // prevent accessing null-node
            }
            std::cout << "Next key is " << next->key << endl;
            
            if (key >= next->key)
                head = next; // continue searching
            else 
                break; // move down
        }
        while (true);

        std::cout << "===\n";

        // insertion point found
        if (level <= insertLevel) {
            // switch pointers
            tmp = head->forward[level];
            head->forward[level] = node;
            node->forward[level] = tmp;
        }
        // go down
    }

}


// create random level for node 
int SkipList::randomLevel()
{ 
    float r = (float) rand() / RAND_MAX;
    int lvl = 0; 

    while (r < P && lvl < LEVELS) 
    { 
        lvl++; 
        r = (float) rand() / RAND_MAX;
    }

    return lvl;
};


void SkipList::print()
{
    std::cout<<"\n*****Skip List*****"<<"\n"; 
    for (int i = 0; i <= LEVELS - 1; i++) 
    { 
        Node * node = head->forward[i]; 
        std::cout << "Level " << i << ": "; 

        while (node != NULL) 
        { 
            std::cout << node->key << " "; 
            node = node->forward[i]; 
        } 
        std::cout << std::endl; 
    } 
}


