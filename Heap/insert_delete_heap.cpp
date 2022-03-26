#include <iostream>
using namespace std;

#define MAX 1000 


//For deletion
void heapify_del(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify_del(arr, n, largest);
    }
}

void deleteRoot(int arr[], int& n)
{
    // Get the last element
    int lastElement = arr[n - 1];
 
    // Replace root with last element
    arr[0] = lastElement;
 
    // Decrease size of heap by 1
    n = n - 1;
 
    // heapify the root node
    heapify_del(arr, n, 0);
}



//for addition
void heapify(int arr[], int n, int i)
{
	// Find parent
	int parent = (i - 1) / 2;

	if (parent >= 0) {
		// For Max-Heap
		// If current node is greater than its parent
		// Swap both of them and call heapify again
		// for the parent
		if (arr[i] > arr[parent]) {
			swap(arr[i], arr[parent]);

			// Recursively heapify the parent node
			heapify(arr, n, parent);
		}
	}
}

// Function to insert a new node to the Heap
void insertNode(int arr[], int& n, int Key)
{
	// Increase the size of Heap by 1
	n = n + 1;

	// Insert the element at end of Heap
	arr[n - 1] = Key;

	// Heapify the new node following a
	// Bottom-up approach
	heapify(arr, n, n - 1);
}

// A utility function to print array of size n
void printArray(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";

	cout << "\n";
}

// Driver Code
int main()
{

	int arr[MAX] = { 10, 5, 3, 2, 4 };

	int n = 5;

	int key = 15;

	insertNode(arr, n, key);

	printArray(arr, n);
	deleteRoot(arr, n);
	printArray(arr, n);

    
	return 0;
}
