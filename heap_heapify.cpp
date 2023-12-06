#include<bits/stdc++.h>
using namespace std;

void maxHeapify(int arr[], int len)
{
    for(int i=(len/2); i>=0; i--)
    {
        int parent = i;
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
            else break;
        }
    }
}

void minHeapify(int arr[], int len)
{
    for(int i=(len/2); i>=0; i--)
    {
        int parent = i;
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
            else break;
        }
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
    cout<<"Array elements, before transforming into heap: \n\n";
    printArray(arr, len);

    maxHeapify(arr, len);
    cout<<"Array elements, after transforming into a max heap: \n\n";
    printArray(arr, len);

    minHeapify(arr, len);
    cout<<"Array elements, after transforming into a min heap: \n\n";
    printArray(arr, len);
}
