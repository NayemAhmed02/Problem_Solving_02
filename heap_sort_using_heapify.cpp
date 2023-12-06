#include<bits/stdc++.h>
using namespace std;

void maxHeapify(int arr[], int len, int parent)
{
    int leftChild = (2 * parent) + 1;
    int rightChild = (2 * parent) + 2;

    while(leftChild < len)
    {
        if((rightChild < len) && (arr[leftChild] > arr[parent]) && (arr[leftChild] > arr[rightChild]))
        {
            swap(arr[leftChild], arr[parent]);
            parent = leftChild;
            leftChild = (2 * parent) + 1;
            rightChild = (2 * parent) + 2;
        }
        else if((rightChild < len) && (arr[rightChild] > arr[parent]) && (arr[leftChild] < arr[rightChild]))
        {
            swap(arr[rightChild], arr[parent]);
            parent = rightChild;
            leftChild = (2 * parent) + 1;
            rightChild = (2 * parent) + 2;
        }
        else if(arr[leftChild] > arr[parent])
        {
            swap(arr[leftChild], arr[parent]);
            break;
        }
        else
            break;
    }
}

void minHeapify(int arr[], int len, int parent)
{

    int leftChild = (2 * parent) + 1;
    int rightChild = (2 * parent) + 2;

    while(leftChild < len)
    {
        if((rightChild < len) && (arr[leftChild] < arr[parent]) && (arr[leftChild] < arr[rightChild]))
        {
            swap(arr[leftChild], arr[parent]);
            parent = leftChild;
            leftChild = (2 * parent) + 1;
            rightChild = (2 * parent) + 2;
        }
        else if((rightChild < len) && (arr[rightChild] < arr[parent]) && (arr[leftChild] > arr[rightChild]))
        {
            swap(arr[rightChild], arr[parent]);
            parent = rightChild;
            leftChild = (2 * parent) + 1;
            rightChild = (2 * parent) + 2;
        }
        else if(arr[leftChild] < arr[parent])
        {
            swap(arr[leftChild], arr[parent]);
            break;
        }
        else
            break;
    }
}

void sortInAscending(int arr[], int len)
{
    // first step -> normal array transfer into a max heap
    for(int i=len/2; i>=0; i--)
    {
        maxHeapify(arr, len, i);
    }

    // second step -> one by one largest element extract and transfer in the end of the array
    for(int i = len-1; i>=0; i--)
    {
        // extract largest element and send to the end of the array
        swap(arr[0], arr[i]);

        // now heapify for correcting root position
        maxHeapify(arr, i, 0);
    }

}

void sortInDescending(int arr[], int len)
{
    // first step -> normal array transfer into a min heap
    for(int i=len/2; i>=0; i--)
    {
        minHeapify(arr, len, i);
    }

    // second step -> one by one smallest element extract and transfer in the end of the array
    for(int i = len-1; i>=0; i--)
    {
        // extract smallest element and send to the end of the array
        swap(arr[0], arr[i]);

        // now heapify for correcting root position
        minHeapify(arr, i, 0);
    }

}


void printArray(int arr[], int len)
{
    for(int i=0; i<len; i++)
    {
        cout<<arr[i]<<"    ";
    }
    cout<<"\n\n";
}

int main()
{
    int len = 11;
    int arr[len] = {10, 5, 15, 20, 25, 22, 27, 28, 12, 8, 35};
    cout<<"Array elements, before sorting: \n\n";
    printArray(arr, len);

    sortInAscending(arr, len);
    cout<<"Array elements, after sorting in ascending order: \n\n";
    printArray(arr, len);

    sortInDescending(arr, len);
    cout<<"Array elements, after sorting in descending order: \n\n";
    printArray(arr, len);
}

