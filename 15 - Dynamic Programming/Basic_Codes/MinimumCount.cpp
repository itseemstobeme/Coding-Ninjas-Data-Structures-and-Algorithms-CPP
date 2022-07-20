#include <iostream>
using namespace std;

#include <cmath>
#include <climits>
//BRUTE FORCE SOLUTION
/*
int minCount(int n)
{
    //n will never be negative as i =1,2,....sqrt(n), hence {n-pow(i,2) >= 0} always
    if (n <= 1)
        return n; //For n==0, sum has been reached hence return 0 as no more operations req
                  //For n==1, 1 operation req => (pow(1,2)) to reach desired sum

    int squareRoot = sqrt(n);
    int count = INT_MAX;
    for (int i = 1; i <= squareRoot; ++i)
    {
        count = min(count, minCount(n - pow(i, 2)));
    }
    return 1 + count; //Adding one indicates the one operation we make, which takes min path to get n to 0 as sum of squares of i,
                      //min path being => min(count,minCount(n-pow(i,2)))
}
*/

//MEMOIZED SOLUTION
/*
int helper_minCount(int* arr,int n)
{
    //n will never be negative as i =1,2,....sqrt(n), hence {n-pow(i,2) >= 0} always
    if (n <= 1)    //Base case
        return n; //For n==0, sum has been reached hence return 0 as no more operations req
                  //For n==1, 1 operation req => (pow(1,2)) to reach desired sum

    if(arr[n]!=-1) 
    return arr[n];
    else
    {
        int squareRoot = sqrt(n);
        int count = INT_MAX;
        for (int i = 1; i <= squareRoot; ++i)
        {
        count = min(count, helper_minCount(arr,n - pow(i, 2)));
        }
        arr[n]=1 + count;
        return arr[n];  //Adding one indicates the one operation we make, which takes min path to get n to 0 as sum of squares of i,
                        //min path being => min(count,helper_minCount(n-pow(i,2)))
    }
}
int minCount(int n)
{
    int* arr=new int[n+1];

    for(int i=0;i<n+1;++i) 
    arr[i]=-1;

    return helper_minCount(arr,n);
}
*/

//DP SOLUTION
int minCount(int n)
{
    int *arr = new int[n + 1];
    arr[0] = 0;
    arr[1] = 1; //Base cases

    for (int i = 2; i <= n  ++i)
    {
        int squareRoot = sqrt(i);
        int mincount = INT_MAX;

        for (int j = 1; j <= squareRoot; ++j)
        {
            mincount = min(mincount, arr[i - (int)pow(j, 2)]);
        }
        arr[i] = 1 + mincount; //Adding one indicates the one operation we make,
                               //which takes min path to get n to 0 as sum of squares of i,
                               //min path being => min(count,helper_minCount(n-pow(i,2)))
    }
    return arr[n];
}
int main()
{
    int n;
    cin >> n;
    cout << minCount(n);
}
/*
Given an integer N, find and return the count of minimum numbers required to represent N as a sum of squares.
That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. The output will be 1, as 1 is the minimum count of numbers required to represent N as sum of squares.
Input format :
The first and the only line of input contains an integer value, 'N'.
Output format :
Print the minimum count of numbers required.
Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec

Sample Input 1 :
12
Sample Output 1 :
3
Explanation of Sample Output 1 :
12 can be represented as : 
A) (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2)

B) (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2)  + (2 ^ 2)

C) (1^2) + (1^2) + (1^2) + (1^2) + (2 ^ 2) + (2 ^ 2)

D) (2 ^ 2) + (2 ^ 2) + (2 ^ 2)

As we can see, the output should be 3.

Sample Input 2 :
9
Sample Output 2 :
1
*/