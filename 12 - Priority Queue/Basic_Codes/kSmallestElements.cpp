#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Approach, if we add first k elements to a MAX PQ, and keep adding k+1 to n elements  if the element to be added
is lesser than the top of PQ,and then keep popping 
the top(max) elements from it simultaneouly, the final PQ will have the k smallest elements 
as the k smallest elements at any given moment always be in the PQ, and won't be removed if we pop the 
topmost element
Finally, pop them out and put into a vector and return it
The point of having k elements in PQ is to make such that addition and deletion from PQ takes O(logk) time
for one element, and O(n*logk) for n elements
*/
#include<queue>
vector<int> kSmallest(int *arr, int n, int k)
{   
    priority_queue<int> pq;
    for(int i=0;i<k;++i)    //making a PQ with no of elements = k
    pq.push(arr[i]);    

    for(int i=k;i<n;++i)    //pushing the rest of elements if they are 
    {                       //greater than the greatest element(top) and popping the top
        if(arr[i] < pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    //Now PQ has only the min elements
    vector<int> ans;
    while(!pq.empty())
    {   
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}
int main()
{
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++)
    {
        cin >> input[i];
    }

    int k;
    cin >> k;

    vector<int> output = kSmallest(input, size, k);
    sort(output.begin(), output.end());

    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << " ";
    }

    delete[] input;
}
/*
You are given with an integer k and an array of integers that contain numbers in random order. Write a program to find k smallest numbers from given array. You need to save them in an array and return it.
Time complexity should be O(n * logk) and space complexity should not be more than O(k).
Note: Order of elements in the output is not important.
Input Format :
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.
The following line contains an integer, that denotes the value of k.
Output Format :
The first and only line of output print k smallest elements. The elements in the output are separated by a single space. 
Constraints:
Time Limit: 1 sec

Sample Input 1 :
13
2 12 9 16 10 5 3 20 25 11 1 8 6 
4
Sample Output 1 :
1 2 3 5 
*/