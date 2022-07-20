#include <iostream>
using namespace std;

//BRUTE FORCE SOLUTION
/*
Approach => Either we can loot a house or not => 0 to n-1 choices from array
If we don't loot (n-1)th house, we can send recursion to get ans for 0 to (n-2)th houses => ie, for (n-1) houses
If we loot (n-1)th house, we can't loot next house(n-2), hence we send recursion to get ans for 
0 to (n-3)th houses => ie, for n-2 houses, and add arr[n-1] to it to show that we've included (n-1)th house in the loot
We take max of both options and return ans
*/
/*
int maxMoneyLooted(int arr[], int n)
{
    if (n <= 0) //Base case, if n == 0, return 0 as no possible houses left to loot
        return 0;

    int loot = arr[n - 1] + maxMoneyLooted(arr, n - 2);
    int notloot = maxMoneyLooted(arr, n - 1);

    return max(loot, notloot);
}
*/

//MEMOIZED SOLUTION => Top Down Approach => going from n-1 to 0, ie, backwards in arr[]
/*
Need for optimization => eg, arr[] =[10 2 30 20 3 50]
If we decide to loot arr[n-1], ie, 50, we call recursion on [10 2 30 20] to calculate and retrieve ans

Later if we decide ignore arr[n-1], ie, 50, we call recursion on [10 2 30 20 3], and then again
if we loot arr[n-1], call will be made on [10 2 30], and if we ignore it call will be made on [10 2 30 20]

Hence, clearly, recursive call repeats for [10 2 30 20]
This will occur for all the positions in array
So, we can memoize it by creating an array ans of size (n+1), and storing max(loot,notloot) of (i-1)th house at ans[i] 
Hence, final ans,ie, call for arr[n-1] will be stored at ans[n]
*/
/*
int helper_loot(int *ans, int *arr, int n)
{
    if (n <= 0)
        return 0;

    if (ans[n] != -1)
        return ans[n];
    else
    {
        int loot = arr[n - 1] + helper_loot(ans, arr, n - 2);
        int notloot = helper_loot(ans, arr, n - 1);

        ans[n] = max(loot, notloot);
        return ans[n];
    }
}
int maxMoneyLooted(int arr[], int n)
{
    int *ans = new int[n + 1];
    for (int i = 0; i <= n; ++i)
        ans[i] = -1;

    return helper_loot(ans, arr, n);
}
*/

//DP SOLUTION => Bottom Up Approach => going from 0 to n-1, ie, forwards in arr[]
int maxMoneyLooted(int arr[], int n)
{
    int *ans = new int[n + 1];
    ans[0] = 0; //Base case

    for (int i = 1; i <= n; ++i)
    {
        int loot, notloot;

        if (i - 2 >= 0)                     //Base case, if (n-2) exists in array, f(n-2) returns a non zero value, else returns 0
            loot = arr[i - 1] + ans[i - 2]; //Here, f(n-2) is ans[i-2], which will either exist if i-2 >=0 , else will be 0
        else
            loot = arr[i - 1];

        notloot = ans[i - 1];
        ans[i] = max(loot, notloot);
    }
    return ans[n];
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

    cout << maxMoneyLooted(arr, n);

    delete[] arr;
}

/*
A thief wants to loot houses. He knows the amount of money in each house. He cannot loot two consecutive houses. Find the maximum amount of money he can loot.
Input format :
The first line of input contains an integer value of 'n'. It is the total number of houses.

The second line of input contains 'n' integer values separated by a single space denoting the amount of money each house has.
Output format :
Print the the maximum money that can be looted.
Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec
Sample Input 1 :
6
5 5 10 100 10 5
Sample Output 1 :
110

Sample Input 2 :
6
10 2 30 20 3 50
Sample Output 2 :
90
Explanation of Sample Output 2 :
Looting first, third, and the last houses([10 + 30 + 50]) will result in the maximum loot, and all the other possible combinations would result in less than 90.
*/