#include <iostream>
#include <vector>
using namespace std;

/*
Approach is same as merging 2 sorted arrays
For 2 sorted arrays, we kept 2 variables i & j to determine index,and a simple arr[i] > arr[j] comparison to compare 2 elements
to add the smaller element to new sorted array and increment i or j if we added the ith or the jth element

For k sorted arrays, we use a MIN PQ to compare k elementsa at a time,pop() and add smallest(top()) to the final array
Since we don't know how many arrays are there, we can't keep i,j,k,l,... variables to keep track of indices
in each of the arrays
Hence the elements added in PQ will be class objects having memebers-> 
(value,array or row number, index at which element is in the array) 

eg.
for input arrays 
1 5 9
45 90 
2 6 78 100 234
0

Since we receive the input as a 2-D vector(or a matrix),
The number 100 in PQ will be a class object like (100,2,3)
Hence, if 100 is at top of PQ and is popped, 
we know the next element to added to PQ will be at (2,3+1)=>(2,4), ie, 234
No of elements in PQ will be k, hence insertion/deletetion will have complexity O(logk)
*/
#include <queue>
class element
{
public:
    int value, row, index;
    element(int value, int row, int index) : value(value), row(row), index(index)
    {
    }
};
class CompareElement
{
public:
    bool operator()(element const &e1, element const &e2)
    {
        //For min priority queue, we need greater<T>, hence symbol used will be '>'
        return e1.value > e2.value;
    }
};
/*OR WE CAN USE the following (no need for a class)
//These two functions are for operator overloading on priority queue with class objects
//ie,comparison b/w two class objects
bool operator<(element const &e1, element const &e2)
{
    return e1.value < e2.value;
}
bool operator>(element const &e1, element const &e2)
{
    return e1.value > e2.value;
}

PQ will be declared inside function() as
priority_queue<element,vector<element>,greater<int>> pq; //Here greater implies MIN PQ, and uses overloaded operators to compare objects

*/
vector<int> mergeKSortedArrays(vector<vector<int> *> input)
{
    priority_queue<element, vector<element>, CompareElement> pq;

    //Create min heap of first elements of k arrays
    for (int i = 0; i < input.size(); ++i)
    {
        element e(input[i]->at(0), i, 0);
        pq.push(e);
    }

    vector<int> ans; //Final ans vector array
    while (!pq.empty())
    {
        element minElement = pq.top(); //min element
        pq.pop();

        int value = minElement.value;
        int row = minElement.row;
        int index = minElement.index;
        ans.push_back(value); //pushing back current min into ans vector

        //check if element at input[row][index+1] exists or not
        if (index + 1 < input[row]->size())
        {
            element newElement(input[row]->at(index + 1), row, index + 1);
            pq.push(newElement);
        }
    }

    return ans;
}
int main()
{
    int k;
    cin >> k;

    vector<vector<int> *> input;

    for (int j = 1; j <= k; j++)
    {
        int size;
        cin >> size;
        vector<int> *current = new vector<int>;

        for (int i = 0; i < size; i++)
        {
            int a;
            cin >> a;
            current->push_back(a);
        }

        input.push_back(current);
    }

    vector<int> output = mergeKSortedArrays(input);

    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << " ";
    }

    return 0;
}

/*
Given k different arrays, which are sorted individually (in ascending order). You need to merge all the given arrays such that output array should be sorted (in ascending order).
Hint : Use Heaps.
Input Format:
The first line of input contains an integer, that denotes value of k.
The following lines of input represent k sorted arrays. Each sorted array uses two lines of input. The first line contains an integer, that denotes the size of the array. The following line contains elements of the array.
Output Format:
The first and only line of output contains space separated elements of the merged and sorted array, as described in the task.
Constraints:
0 <= k <= 1000
0 <= n1, n2 <= 10000
Time Limit: 1 second

Sample Input 1:
4
3
1 5 9
2
45 90
5
2 6 78 100 234
1
0
Sample Output 1:
0 1 2 5 6 9 45 78 90 100 234
*/