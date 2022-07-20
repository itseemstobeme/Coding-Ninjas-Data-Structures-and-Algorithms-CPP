#include<iostream>
using namespace std;

//Similar to 01 Knapsack, but here we have infinite supply of weights from weights[] array, ie, infinite supply of denominations in denom[] array

//Also similar problem where we have to find no of ways of 'n' as a sum of numbers from 1 to k
//Link => https://stackoverflow.com/questions/58486802/find-the-number-of-ways-to-find-the-total-sum-value-using-the-range-1-to-k
//eg, n = 5, k = 3 , possible sums are (1,1,1,1,1),(1,1,1,2),(1,1,3),(2,3),(1,2,2) => 5 ways
//eg, n = 16, k = 4, possible sums are ... => 64 ways
//Hence for (n,k) solve by making an array denom[] of [1,2,3,...,k], val = n(n being 5 or 16)
//and numDenominations(n of below function) = k (ie, size of denom[]) array and send as
// countwaysToMakeChange(denom[],k,vak);

//BRUTE FORCE SOLUTION
/*
int countWaysToMakeChange(int denom[], int n, int val)
{
    if (n == 0 || val < 0)
        return 0;
    if (val == 0)
        return 1;

    int include = countWaysToMakeChange(denom, n, val - denom[n - 1]); //Including current denomination in our change,so we have option to include
                                                                       //current denomination again, infinitely, hence n is unchanged(so that we can include it in our change later)

    int exclude = countWaysToMakeChange(denom, n - 1, val); //Excluding current denomination in our change, ie, we will never use it
                                                            //Hence, n changed to n-1 & val unchanged to signify current denomination
                                                            //will never be used in our change

    return exclude + include;
}
*/

//MEMOIZED  => Top Down Approach => going from n-1 to 0, ie, backwards in denom[] array
//Need for optimization and repeating subproblems => See from notes
/*
int helper(int *arr[], int denom[], int n, int val)
{
    if (n == 0 || val < 0)
        return 0;
    if (val == 0)
        return 1;

    if (arr[n][val] != -1)
        return arr[n][val];

    int include = helper(arr, denom, n, val - denom[n - 1]); //Including current denomination in our change,so we have option to include
                                                             //current denomination again, infinitely, hence n is unchanged(so that we can include it in our change later)

    int exclude = helper(arr, denom, n - 1, val); //Excluding current denomination in our change, ie, we will never use it
                                                  //Hence, n changed to n-1 & val unchanged to signify current denomination
                                                  //will never be used in our change
    arr[n][val] = include + exclude;
    return arr[n][val];
}
int countWaysToMakeChange(int denom[], int n, int val)
{
    int **arr = new int *[n + 1];
    for (int i = 0; i <= n; ++i)
    {
        arr[i] = new int[val + 1];
        for (int j = 0; j <= val; ++j)
            arr[i][j] = -1;
    }
    return helper(arr, denom, n, val);
}
*/

//DP SOLUTION => Bottom Up Approach => going from 0 to n-1, ie, forwards in denom[] array
int countWaysToMakeChange(int denom[], int n, int val)
{
    int **arr = new int *[n + 1]; //Making an array of size (n+1,val+1)
    for (int i = 0; i <= n; ++i)
        arr[i] = new int[val + 1];

    //Base Case Filling
    for (int i = 0; i <= n; ++i) //Base case, if val == 0, return 1
        arr[i][0] = 1;

    for (int j = 0; j <= val; ++j) //Base case, if n == 0, return 0
        arr[0][j] = 0;

    //SOLVING USING DP
    for (int i = 1; i <= n; ++i) //i is equivalent to n in recursive calls
    {
        for (int j = 1; j <= val; ++j) //j is equivalent to val in recursive calls
        {
            int include = 0, exclude;

            if (j - denom[i - 1] >= 0)
                include = arr[i][j - denom[i - 1]]; //equivalent to count(denom, n, val - denom[n - 1])

            exclude = arr[i - 1][j]; //equivalent to count(denom, n-1, val)

            arr[i][j] = include + exclude;
        }
    }
    return arr[n][val];
}
int main()
{
    int numDenominations;
    cin >> numDenominations;

    int *denominations = new int[numDenominations];

    for (int i = 0; i < numDenominations; i++)
    {
        cin >> denominations[i];
    }

    int value;
    cin >> value;

    cout << countWaysToMakeChange(denominations, numDenominations, value);

    delete[] denominations;
}

/*
For the given infinite supply of coins of each of denominations, D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the total number of ways W, in which you can make the change for Value V using coins of denominations D.
Return 0 if the change isn't possible.
Input Format
The first line of the input contains an integer value N, which denotes the total number of denominations.

The second line of input contains N values, separated by a single space. These values denote the value of denomination.

The third line of the input contains an integer value, that denotes the value of V.
Output Format
Print the total total number of ways i.e. W.
Constraints :
1 <= n <= 10
1 <= V <= 1000

Time Limit: 1sec

Sample Input 1 :
3
1 2 3
4
Sample Output 1 :
4
Explanation to Sample Input 1 :
Number of ways are - 4 total i.e. (1,1,1,1), (1,1, 2), (1, 3) and (2, 2).

Sample Input 2 :
6
1 2 3 4 5 6
250
Sample Output 2 :
13868903
*/