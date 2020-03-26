#include "heapsort.cpp"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#define N 50


Node ** read()
{
	ifstream input("data.txt");

	int n;
	input >> n;

	Node ** arr = new Node*[n];

	int key;
	string data;
	for (int i = 0; i < n; i++)
	{
		input >> key;
		input >> data;
		arr[i] = new Node(key, data);
	}

	return arr;
}

int main() 
{ 
	Node ** arr = read();

	heapSort(arr, N);

	for (int i = 0; i < N; i++)
		cout << arr[i]->key << " " << arr[i]->data << endl;


} 
