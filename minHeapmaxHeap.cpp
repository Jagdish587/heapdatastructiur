#include <iostream>
using namespace std;


void maxHeap(int arr[], int index, int size)
{
    int largest = index;
    int left = 2*index + 1;
    int right = 2*index + 2;

    if(left < size && arr[left] > arr[largest])
        largest = left;

    if(right < size && arr[right] > arr[largest])
        largest = right;

    if(largest != index) {
        swap(arr[index],arr[largest]);
        maxHeap(arr, largest, size);
    }

}

void minHeap(int arr[], int index, int size)
{
    int smallest = index;
    int left = 2*index + 1;
    int right = 2*index + 2;

    if(left <= size && arr[smallest] > arr[left])
        smallest = left;

    if(right <= size && arr[smallest] > arr[right])
        smallest = right;

    if(smallest != index) {
        swap(arr[index],arr[smallest]);
        minHeap(arr, smallest, size);
    }

}


void buildMaxHeap()
{
    int arr[] = {4, 7, 8, 3, 2, 6, 5}; //o/p : 8 7 6 3 2 4 5

    // int arr[] = {1, 4, 3, 7, 8, 9, 10}; // o/p : 10 8 9 7 4 1 3
    int size = sizeof(arr)/sizeof (arr[0]);

    for (int index = (size/2) -1 ; index>=0; index--) {
        maxHeap(arr, index, size);
    }


    for(auto &it : arr)
        cout<<it<<" ";

    cout<<endl;
}

void buildMinHeap()
{
    int arr[] = {10, 8, 9, 7, 6, 5, 4}; // o/p : 4 5 6 7 8 10 9

    int size = sizeof(arr)/sizeof (arr[0]);

    for (int index = (size/2) -1 ; index>=0; index--) {
        minHeap(arr, index, size);
    }

    for(auto &it : arr)
        cout<<it<<" ";
}



int main()
{
	// program to show max Heap and Min Heap using array
    buildMaxHeap();
    buildMinHeap();

    cout<<endl;
}
