#include <iostream>
#include <vector>
using namespace std;

/*
To do it in less than O(nlogn), we can use PQ to do it in O(nlogk)
Take a MIN PQ, add first k elements to it, 
so that insertion/deletion for n elements will have complexity O(n * h), h of heap=log k => O(n*logk)
Now min element will be on top and rest elements will be in subtrees
That min element is the kth largest in the heap(k total elements in heap, min element on top will be kth largest)
(eg, if k=3 & {19,7,10} are added in min PQ, order will be {7,19,10}, 7 being the 3rd largest is on the top)
Traverse rest of array, if arr[i] > PQ.top(), a bigger element than top has been found, 
hence top is no longer kth largest
pop() the top and push(arr[i]), now heapification occurs and kth largest element once again is on the top
When all elements have been compared and added, final heap will have k elements, and top will be the kth largest element
*/
#include <queue>
int kthLargest(int *arr, int n, int k)
{
    if (n == 0)
        return -1;

    priority_queue<int, vector<int>, greater<int>> pq;

    //Making heap with k elements, to make complexity of adding/removing as O(logk)
    for (int i = 0; i < k; ++i)
        pq.push(arr[i]);

    //Traversing rest of elements, popping top() and adding element if arr[i] > top()
    for (int i = k; i < n; ++i)
    {
        if (arr[i] > pq.top())
        {
            pq.pop(); //popping done first cause if not, ins/del becomes O(log(k+1)), increases complexity
            pq.push(arr[i]);
        }
    }

    return pq.top();
}
int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    cout << kthLargest(arr, n, k);

    delete[] arr;
}

/*
Given an array A of random integers and an integer k, find and return the kth largest element in the array.
Note: Try to do this question in less than O(N * logN) time.
Input Format :
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.
The following contains an integer, that denotes the value of k.
Output Format :
The first and only line of output contains the kth largest element
Constraints :
1 <= N, Ai, k <= 10^5
Time Limit: 1 sec

Sample Input 1 :
6
9 4 8 7 11 3
2
Sample Output 1 :
9

Sample Input 2 :
8
2 6 10 11 13 4 1 20
4
Sample Output 2 :
10
*/