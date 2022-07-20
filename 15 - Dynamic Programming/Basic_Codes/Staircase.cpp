#include <iostream>
using namespace std;

//BRUTE FORCE RECURSIVE
/*
int staircase(int n)
{
    if (n < 0)      //Base case, negative value means will overskipped the required stair, no hops possible
        return 0;
    if (n == 0)     //Base case, zero means will perfectly landed on required stair, ie, one hop req
        return 1;

    return staircase(n - 1) + staircase(n - 2) + staircase(n - 3);  //No of ways if jumps of 1, 2, and 3 are made
}
*/

//MEMOIZED SOLUTION
/*
int helper_staircase(int arr[],int n)
{
    if (n < 0)      //Base case, negative value means will overskipped the required stair, no hops possible
        return 0;
    if (n == 0)     //Base case, zero means will perfectly landed on required stair, ie, one hop req
        return 1;

    if(arr[n]!=-1)
    return arr[n];
    else
    {
        arr[n]=helper_staircase(arr,n-1)+helper_staircase(arr,n-2)+helper_staircase(arr,n-3);
        return arr[n];
    }
}
int staircase(int n)
{
    int* arr=new int[n+1];

    for(int i=0;i<n+1;++i)
    arr[i]=-1;

    return helper_staircase(arr,n);
}
*/

//DP SOLUTION
int staircase(int n)
{
    int *arr = new int[n + 1];
    arr[0] = 1; //Base case, zero means will perfectly landed on required stair, ie, one hop req

    for (int i = 1; i <= n; ++i)
    {
        arr[i] = arr[i - 1]; //initialize with staircase(n-1), as (i-1) will always exist, hence arr[i] no longer holds garbage
        if (i - 2 >= 0)
            arr[i] += arr[i - 2]; //if (i-2) exists in array, add no of ways
        if (i - 3 >= 0)
            arr[i] += arr[i - 3]; //if (i-3) exists in array, add no of ways
    }
    return arr[n];
}
int main()
{
	int n;
	cin >> n;
	cout << staircase(n);
}

/*
A child runs up a staircase with 'n' steps and can hop either 1 step, 2 steps or 3 steps at a time. 
Implement a method to count and return all possible ways in which the child can run-up to the stairs.
Input format :
The first and the only line of input contains an integer value, 'n', denoting the total number of steps.
Output format :
Print the total possible number of ways.
 Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec
Sample Input 1:
4
Sample Output 1:
7
Sample Input 2:
10
Sample Output 2:
274
*/