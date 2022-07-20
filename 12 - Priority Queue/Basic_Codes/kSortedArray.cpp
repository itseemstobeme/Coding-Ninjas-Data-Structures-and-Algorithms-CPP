#include<iostream>
#include<queue>
using namespace std;

//Sorting the kSorted Array in descending order, ie, using max priority queue
void kSortedArray(int* arr, int n, int k)
{
    priority_queue<int> pq; // max by default
    for(int i=0;i<k;++i)    //Adding first k elements (0 to k-1)
    pq.push(arr[i]);

    int arrayIndex=0;   // to figure out position of element to be inserted in array
    for(int i=k;i<n;++i)
    {
        arr[arrayIndex++]=pq.top(); //add max of pq to array
        pq.pop();                   //remove max
        pq.push(arr[i]);            //add next elements
    }

    //k elements still remain in PQ, must pop and add in array
    while(!pq.empty())  
    {
        arr[arrayIndex++]=pq.top(); //add max of pq to array
        pq.pop();  
    }
}
int main()
{
    int n;
    cin>>n;
    int* arr=new int[n];
    for(int i=0;i<n;++i)
    cin>>arr[i];
    
    int k;
    cin>>k;
    kSortedArray(arr,n,k);
    for(int i=0;i<n;++i)
    cout<<arr[i]<<" ";

    delete[] arr;
}
/*
Given an array of n elements, where each element is at most k, ie 0 to k-1 positions away from its target position, 
devise an algorithm that sorts in O(n log k) time, instead of O(n log n)

For example, let us consider k is 3, an element at index 7 in the sorted array, 
it can go in 0 to (3-1) = 0 to 2 in either direction, hence
can be at indexes 5, 6, 7, 8, 9 in the given array.

Sample Input 1 : 
5
10 12 6 7 9
3
Sample Output 1:
12 10 9 7 6
*/