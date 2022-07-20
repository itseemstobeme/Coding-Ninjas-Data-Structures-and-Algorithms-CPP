#include <iostream>
using namespace std;

/*
void heapSort(int arr[], int n)
{
    for (int i = 1; i < n; ++i)
    {
        int childIndex = i;
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (arr[childIndex] < arr[parentIndex])
                swap(arr[childIndex], arr[parentIndex]);
            else
                break;
            childIndex = parentIndex;
        }
    }

    
    for (int i = n - 1; i > 0; --i)
    {
        swap(arr[0], arr[i]); //Swapping first and final elements
        int parentIndex = 0;
        while (parentIndex < i)     //ie, lesser than the poisition of just swapped element at end, making heap size from 0 to i-1
        {
            int leftChild = 2 * parentIndex + 1;
            int rightChild = 2 * parentIndex + 2;
            int childIndex;
            if (rightChild < i)
            {
                childIndex = arr[leftChild] < arr[rightChild] ? leftChild : rightChild;
            }
            else
            {
                if (leftChild < i)
                    childIndex = leftChild;
                else
                    break;
            }
            if (arr[parentIndex] > arr[childIndex])
                swap(arr[childIndex], arr[parentIndex]);

            else
                break;
            parentIndex = childIndex;
        }
    }
}
*/
void heapSort(int* arr,int n)
{   
    //For making heap
    for(int heapIndex=0;heapIndex<n;++heapIndex)
    {
        int childIndex=heapIndex;
        int parentIndex=(childIndex-1)/2;
        while(parentIndex >= 0)
        {   
            if(arr[childIndex] < arr[parentIndex])
            {
                swap(arr[childIndex],arr[parentIndex]);
                childIndex=parentIndex;
            }
            else
            break;
        }
    }

    //Popping elements(ie, min elements as it is MinHeap) and putting in back
    //popping here is done by 1->swapping first(smallest) and last elements
    //2->making size of total heap shorter
    //And finally down heapify is done in new shorter heap
    for(int heapIndex=n-1;heapIndex>=0;)
    {   
        swap(arr[0],arr[heapIndex]);    //swapping
        --heapIndex;    //excluding now swapped last element from heap, ie, popping

        //Now down-heapify remaining heap excluding the recently popped element
        int parentIndex=0;
        while(parentIndex <= heapIndex)
        {
            int leftChild=2*parentIndex+1;
            int rightChild=2*parentIndex+2;
            int childIndex=parentIndex;
            if(rightChild <= heapIndex)
            {
                childIndex = arr[leftChild] < arr[rightChild] ? leftChild : rightChild ;
            }
            else
            if(leftChild <=  heapIndex)
                childIndex=leftChild;
            
            if(arr[parentIndex] > arr[childIndex])
            {
                swap(arr[parentIndex],arr[childIndex]);
                parentIndex=childIndex;
            }
            else
            break;
        }
    }
}
int main() {
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> input[i];
    } 

    heapSort(input, size);

    for (int i = 0; i < size; i++) {
        cout << input[i] << " ";
    } 

    delete[] input;
}
/*
Given an integer array of size N. Sort this array (in decreasing order) using heap sort.
Note: Space complexity should be O(1).
Input Format:
The first line of input contains an integer, that denotes the value of the size of the array or N.
The following line contains N space separated integers, that denote the value of the elements of the array.
Output Format :
The first and only line of output contains array elements after sorting. The elements of the array in the output are separated by single space.
Constraints :
1 <= n <= 10^6
Time Limit: 1 sec

Sample Input 1:
6 
2 6 8 5 4 3
Sample Output 1:
8 6 5 4 3 2
*/