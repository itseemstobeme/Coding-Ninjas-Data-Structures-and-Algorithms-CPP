#include <iostream>
using namespace std;

/*Approach => any BT of height h can be visualized as 
              (root)
           /          \
    (leftSubtree)    (rightSubtree)

For a balanced BT, we know |lh - rh| <=1 at every node
Hence for a height h, all possible combinations of leftSubtree and rightSubtree heights, respectively are
(h-1,h-1) , (h-1,h-2) , (h-2,h-1)   {max height of either subtree can be (h-1)}
For all 3 combinations, |lh - rh| <= 1 is satisfied

Hence for finding combinations of BTs with above heights will be 
EQUATION => f(h-1)*f(h-1) + f(h-1)*f(h-2) + f(h-2)*f(h-1) => f(h-1)*f(h-1) + 2 *f(h-1)*f(h-2)

Multiplication is done in order to find all possible combinations of left and right subtrees with those heights
We can reduce no of function calls by calling f(h-1) and f(h-2) only once, storing them in some variables and then
using them in above equation
*/
#define mod 1000000007
//BRUTE FORCE SOLUTION
/*
int balancedBTs(int h) //h => height of Binary Tree
{

    if (h <= 1)   //Base Case
        return 1; //For height == 0 OR 1, a singular possible BT => empty BT OR a BT with just the root, respectively

    //(h-1) or (h-2) will always be >=0 for recursive calls as if(h<=1)
    // base case will occur and return, and the following recursive calls will not be made

    long long h1 = balancedBTs(h - 1); //For finding count of subtrees with (h-1) height
    long long h2 = balancedBTs(h - 2); //For finding count of subtrees with (h-2) height

    long long a = ((h1 % mod) * (h1 % mod)) % mod;
    long long b = ((2%mod) * (h1 % mod) * (h2 % mod)) % mod; 
    return (a+b)%mod;
}
*/

//MEMOIZED SOLUTION
/*
Just like fibonacci, 2 calls f(n-1),f(n-2) is made, and we know f(n-1) will call => n-2,n-3,n-4,....BaseCase(n<=1)
Hence when f(n-2){already calculated} is called,
it'll again make calls for n-3,... & n-4,.... which are also already calculated
Hence, repeated function calls, can be avoided by using memoization or DP
*/
/*
long long helper_BTs(long long arr[], int h)
{
    if (h <= 1)   //Base Case
        return 1; //For height == 0 OR 1, a singular possible BT => empty BT OR a BT with just the root, respectively

    if (arr[h] != -1)
        return arr[h];
    else
    {
        long long h1 = helper_BTs(arr, h - 1); //For finding count of subtrees with (h-1) height
        long long h2 = helper_BTs(arr, h - 2); //For finding count of subtrees with (h-2) height

        long long a = ((h1 % mod) * (h1 % mod)) % mod;
        long long b = ((2 % mod) * (h1 % mod) * (h2 % mod)) % mod;
        arr[h] = (a + b) % mod;
        return arr[h];
    }
}
int balancedBTs(int h) //h => height of Binary Tree
{
    long long *arr = new long long[h + 1]; //(h+1) unique calls

    for (int i = 0; i < h + 1; ++i)
        arr[i] = -1;

    return helper_BTs(arr, h);
}

*/

//DP SOLUTION
int balancedBTs(int h) //h => height of Binary Tree
{
    long long *arr = new long long[h + 1];

    arr[0] = arr[1] = 1; //Base Case

    for (int i = 2; i <= h; ++i)
    {
        long long h1 = arr[i - 1]; //For finding count of subtrees with (i-1) => (h-1) height
        long long h2 = arr[i - 2]; //For finding count of subtrees with (i-2) => (h-2) height

        long long a = ((h1 % mod) * (h1 % mod)) % mod;
        long long b = ((2 % mod) * (h1 % mod) * (h2 % mod)) % mod;
        arr[i] = (a + b) % mod;
    }
    return arr[h];
}

int main()
{
    int n;
    cin >> n;
    cout << balancedBTs(n);
}

/*
Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
This number can be huge, so, return output modulus 10^9 + 7.
Write a simple recursive solution.
Input Format :
The first and only line of input contains an integer, that denotes the value of h. Here, h is the height of the tree.
Output Format :
The first and only line of output contains the count of balanced binary trees modulus 10^9 + 7.
Constraints :
1 <= h <= 24
Time Limit: 1 sec

Sample Input 1:
3
Sample Output 1:
15

Sample Input 2:
4
Sample Output 2:
315
*/