/**
 * Based on GeeksForGeeks article
 * https://www.geeksforgeeks.org/heap-sort/
 */

#include <iostream>
using namespace std; 

struct Node {
	int key;
	string data;
	Node (int k, string d) { key = k; data = d;}
};


void heapify(Node* arr[], int n, int i) 
{ 
	int largest = i; // Initialize largest as root 
	int l = 2*i + 1; // left
	int r = 2*i + 2; // right

	// If left child is larger than root 
	if (l < n && arr[l]->key > arr[largest]->key) 
		largest = l;

	// If right child is larger than largest so far 
	if (r < n && arr[r]->key > arr[largest]->key) 
		largest = r;

	// If largest is not root 
	if (largest != i) 
	{ 
		swap(arr[i], arr[largest]);

		// Recursively heapify the affected sub-tree 
		heapify(arr, n, largest);
	} 
} 

// main function to do heap sort 
void heapSort(Node* arr[], int n) 
{ 
	// Build heap (rearrange array) 
	for (int i = n / 2 - 1; i >= 0; i--) 
		heapify(arr, n, i);

	// One by one extract an element from heap 
	for (int i = n - 1; i >= 0; i--) 
	{ 
		// Move current root to end 
		swap(arr[0], arr[i]); 

		// call max heapify on the reduced heap 
		heapify(arr, i, 0); 
	} 
} 


