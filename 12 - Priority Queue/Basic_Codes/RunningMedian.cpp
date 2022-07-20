#include <iostream>
using namespace std;

#include<queue>
void printRunningMedian(int *arr, int n)
{
    if(n==0)
    return;

    priority_queue<int> max; //max PQ
    priority_queue<int,vector<int>,greater<int>> min; //min PQ

    for(int i=0;i<n;++i)
    {

        //Pushing the ith element into either min or max PQ
        if(!min.empty() || !max.empty())    //In every case except one, min and max PQ will never be empty 
        {                                   //because |no_elements_minPQ - no_elements_maxPQ| <= 1 
            if(arr[i] > min.top())
            min.push(arr[i]);
            else
            max.push(arr[i]);
        }
        else
        min.push(arr[i]);                  // Only when the first element is pushed into min PQ, min and max will both be empty
    
        //Making sure the min and max PQ are in such a way that
        //min element of later larger half of array is always on top in MIN PQ and all elements greater than it are its children
        //and max element of smaller first half of array is always on top in MAX PQ and all elements smaller than it are its children
        //The only way to do this is by ensuring |no_elements_minPQ - no_elements_maxPQ| <= 1
        //If not,pop element from PQ having relative size greater than 1 and push it into the other PQ
        //Since both are PQ, the min and max elements of PQ automatically appear on tops of PQs

        if(min.size() > max.size()+1)
        {
            max.push(min.top());
            min.pop();
        }
        else
        if(max.size() > min.size() + 1)
        {
            min.push(max.top());
            max.pop();
        }
        //Printing the running median
        if(min.size()==max.size())
        cout<<(min.top()+max.top())/2<<" ";
        else
        if(min.size() > max.size())
        cout<<min.top()<<" ";
        else
        cout<<max.top()<<" ";
    }

}
int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    printRunningMedian(arr, n);
    delete[] arr;
}

/*
You are given a stream of 'N' integers. For every 'i-th' integer added to the running list of integers, print the resulting median.
Print only the integer part of the median.
Input Format :
The first line of input contains an integer 'N', denoting the number of integers in the stream.

The second line of input contains 'N' integers separated by a single space.
Output Format :
Print the running median for every integer added to the running list in one line (space-separated).
Input Constraints
0 <= N <= 10 ^ 5
1 <= ARR[i] <= 10 ^ 5

Time Limit: 1 sec
Sample Input 1 :
6
6 2 1 3 7 5
Sample Output 1 :
6 4 2 2 3 4
Explanation of Sample Output 1 :
S = {6}, median = 6
S = {6, 2} -> {2, 6}, median = 4
S = {6, 2, 1} -> {1, 2, 6}, median = 2
S = {6, 2, 1, 3} -> {1, 2, 3, 6}, median = 2
S = {6, 2, 1, 3, 7} -> {1, 2, 3, 6, 7}, median = 3
S = {6, 2, 1, 3, 7, 5} -> {1, 2, 3, 5, 6, 7}, median = 4

Sample Input 2 :
5
5 4 3 2 1
Sample Output 2 :
5 4 4 3 3
*/