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

void heapSort()
{
    int arr[] = {4, 3, 7, 1, 8, 5};

    int size = sizeof(arr)/sizeof(arr[0]);

    for (int index = (size/2) -1 ; index>=0; index--) {
        maxHeap(arr, index, size);
    }

    for (int lastindex = size -1 ; lastindex>=0; lastindex--) {
        swap(arr[0],arr[lastindex]);
        maxHeap(arr, 0, lastindex);
    }


    for(auto &it : arr)
        cout<<it<<" ";

    cout<<endl;
}


int main()
{

    heapSort();


    cout<<endl;
}
