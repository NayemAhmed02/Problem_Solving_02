#include<bits/stdc++.h>
using namespace std;

class Heap {
private:
    // Pointer to store array created
    // using new keyword
    int* arr = NULL;
    // Size of array
    int size;

    // Container size
    int capacity;

public:
    // Default constructor with size 1
    Heap()
    {
        capacity = 64;
        size = 0;
        arr = new int[capacity];
    }

    void insertIntoHeap(int ele)
    {
        arr[size] = ele;
        size++;

        int child = size - 1;
        int parent = (child - 1) / 2;

        while(parent >= 0)
        {
            if(arr[child] > arr[parent]) {
                swap(arr[child], arr[parent]);
                child = parent;
                parent = (child - 1) / 2;
            }
            else break;
        }
    }

    void deleteFromHeap()
    {
        swap(arr[0], arr[size-1]);
        size--;

        int parent = 0;
        int leftChild = (2 * parent) + 1;
        int rightChild = (2 * parent) + 2;

        while(leftChild < size)
        {
            if((rightChild < size) && (arr[leftChild] > arr[parent]) && (arr[leftChild] > arr[rightChild]))
            {
                swap(arr[leftChild], arr[parent]);
                parent = leftChild;
                leftChild = (2 * parent) + 1;
                rightChild = (2 * parent) + 2;
            }
            else if((rightChild < size) &&(arr[rightChild] > arr[parent]) && (arr[leftChild] < arr[rightChild]))
            {
                swap(arr[rightChild], arr[parent]);
                parent = rightChild;
                leftChild = (2 * parent) + 1;
                rightChild = (2 * parent) + 2;
            }
            else if(arr[leftChild] > arr[parent]) {
                swap(arr[leftChild], arr[parent]);
                break;
            }
            else break;
        }
    }

    void printHeap()
    {
        //cout<<"All Heap elements are: \n\n";
        for(int i=0; i<size; i++)
        {
            cout<<arr[i]<<"    ";
        }
        cout<<"\n\n";

    }

};

// 10 5 15 20 25 22 27 28 12 8 35
int main()
{
    Heap da;
    int nums[] = {10, 5, 15, 20, 25, 22, 27, 28, 12, 8, 35};

    for(int i=0; i<11; i++) {
        da.insertIntoHeap(nums[i]);
    }

    cout<<"Array, After transforming into a max heap: \n\n";
    da.printHeap();


    for(int i=0; i<11; i++)
    {
       cout<<"\n\nAfter delete largest element from Heap: \n\n";
       da.deleteFromHeap();
       da.printHeap();
    }

    return 0;
}
