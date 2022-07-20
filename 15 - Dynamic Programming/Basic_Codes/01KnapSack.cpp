#include <iostream>
using namespace std;

#include <climits>
//BRUTE FORCE SOLUTION => Time complexity => O(n^2) for all unique weights in weights[], O(2^n) for non unique weights in weights[]
/*
int knapsack(int weights[], int values[], int n, int maxWeight)
{
    if (maxWeight < 0)      //if weight is < 0, it means item cannot be included, hence max(INT_MIN,dont_include) => dont_include
        return INT_MIN;
    if (maxWeight == 0 || n == 0)
        return 0;

    int include = values[0] + knapsack(weights + 1, values + 1, n - 1, maxWeight - weights[0]); //Include current weight, hence value is added
    int exclude = knapsack(weights + 1, values + 1, n - 1, maxWeight);                     //Don't include current weight

    return max(include, exclude);
}
*/

//MEMOIZED => Bottom up approach => going from 0 to n-1 in weights[] and values[] arrays using recursion
/*
Need for optimization => See from Notes (for non unique weights, we will see repeating subproblems, in which case
complexity will become exponential)
*/
/*
int helper_knapsack(int** arr,int weights[], int values[], int n, int maxWeight)
{
    if (maxWeight < 0) //if weight is < 0, it means item cannot be included, hence max(INT_MIN,dont_include) => dont_include
        return INT_MIN;
    if (maxWeight == 0 || n == 0)
        return 0;

    if(arr[n][maxWeight]!=-1)
        return arr[n][maxWeight];
    else
    {
        int include = values[0] + helper_knapsack(arr,weights + 1, values + 1, n - 1, maxWeight - weights[0]); //Include current weight, hence value is added
        int exclude = helper_knapsack(arr,weights + 1, values + 1, n - 1, maxWeight);                     //Don't include current weight

        arr[n][maxWeight] = max(include, exclude);
        return arr[n][maxWeight];
    }
}   
int knapsack(int weights[], int values[], int n, int maxWeight)
{
    int** arr = new int*[n+1];
    for(int i=0;i<=n;++i)
    {
        arr[i]=new int[maxWeight+1];
        for(int j=0;j<=maxWeight;++j)
            arr[i][j]=-1;
    }
    
    return helper_knapsack(arr,weights,values,n,maxWeight);
}
*/

//DP SOLUTION => Bottom up approach => going from n-1 to 0 in weights[] and values[] array using iteration
//Can also done with O(maxWeight) space complexity, see from GFG
int knapsack(int weights[], int values[], int n, int maxWeight)
{
    int **arr = new int *[n + 1];
    for (int i = 0; i <= n; ++i)
        arr[i] = new int[maxWeight + 1];

    //Base Case Filling
    for (int i = 0; i <= n; ++i) //Base case, if n == 0, return 0
        arr[i][0] = 0;
    for (int j = 0; j <= maxWeight; ++j) //Base case, if maxWeight == 0, return 0
        arr[0][j] = 0;

    //Base case of maxWeight < 0 can't be represented in array format, we must add a check for this base case
    //inside the loop

    //DP Solution => bottom up approach
    //Important analogies to recursion=>
    //(n in recursion) => i , (maxWeight in recursion) => j , hence (weights[0] & values[0] in recurion) => weights[n-i] (n-i => i - i as n == i in iteratiion)
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= maxWeight; ++j)
        {
            int include = INT_MIN, exclude; //Base case for include, if maxWeight(here => j) - weights[0](here=>weights[n-i]) < 0, include =>INT_MIN

            if (j - weights[n - i] >= 0)
                include = values[n - i] + arr[i - 1][j - weights[n - i]]; //Same as recursion, when included, subtract 1 from n(ie,i) => i - 1
                                                                          //and subtract weights[0](ie,[n-i]) from maxWeight(ie,j) => j -weights[n-i]

            exclude = arr[i - 1][j]; //Same as recursion, when not included, simply subtract 1 from n, ie(i) => i - 1

            arr[i][j] = max(include, exclude);
        }
    }
    return arr[n][maxWeight];
}

int main()
{
    int n;
    cin >> n;

    int *weights = new int[n];
    int *values = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }

    int maxWeight;
    cin >> maxWeight;

    cout << knapsack(weights, values, n, maxWeight) << endl;

    delete[] weights;
    delete[] values;
}
/*
A thief robbing a store can carry a maximal weight of W into his knapsack. There are N items, and i-th item weigh 'Wi' and the value being 'Vi.' What would be the maximum value V, that the thief can steal?
Input Format :
The first line of the input contains an integer value N, which denotes the total number of items.

The second line of input contains the N number of weights separated by a single space.

The third line of input contains the N number of values separated by a single space.

The fourth line of the input contains an integer value W, which denotes the maximum weight the thief can steal.
Output Format :
Print the maximum value of V that the thief can steal.
Constraints :
1 <= N <= 20
1<= Wi <= 100
1 <= Vi <= 100

Time Limit: 1 sec

Sample Input 1 :
4
1 2 4 5
5 4 8 6
5
Sample Output 1 :
13

Sample Input 2 :
5
12 7 11 8 9
24 13 23 15 16
26
Sample Output 2 :
51
*/