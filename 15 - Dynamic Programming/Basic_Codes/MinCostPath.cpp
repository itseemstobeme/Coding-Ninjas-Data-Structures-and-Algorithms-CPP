#include<iostream>
using namespace std;

#include <climits>
/*
Approach => 
For minCostPath from (0,0) to (m-1,n-1), we can move (i,j) starting from (0,0) in following ways =>
(i+1,j) , (i,j+1) , (i+1,j+1)

We call recursion on all three paths starting from (0,0) till i=m-1,j=n-1, and return min of all 3 calculations,
ie, the cost of the minCostPath
*/

//BRUTE FORCE SOLUTION
/*
int mincostpath(int** arr,int i,int j,int m,int n)
{
	if(i >= m || j >= n	) 	//invalid value for i or j will return INT_MAX, ie, that path will
		return INT_MAX;		//not be included while using min() function as other values will always be smaller than INT_MAX

	if(i == m-1 && j == n-1) //Base Case, path found
		return arr[i][j];	 //ie, arr[m-1][n-1]

	//Finding cost of paths of each move that can be made
	int pA = mincostpath(arr,i+1,j,m,n);	//Moving down a row
	int pB = mincostpath(arr,i,j+1,m,n);	//Moving right a column
	int pC = mincostpath(arr,i+1,j+1,m,n);	//Moving diagonally downwards

	return arr[i][j] + min(pA,min(pB,pC));	//total cost is cost of min path + value at each cell(particular position) 
                                            //in array which has to be included in minCostPath
}
int minCostPath(int** arr,int m,int n)
{
	return mincostpath(arr,0,0,m,n);	
}
*/

//MEMOIZED	=> TOP-DOWN APPROACH => going from  (0,0) to (m-1,n-1) 
/*
Need for optimization from Brute Force => 
eg, m = 5, n= 5
We need to find minCostPath from (0,0) to (4,4)
Calls made at every cell => (i+1,j) , (i,j+1) , (i+1,j+1)
For (0,0) 
1)it'll first call for (1,0) => which'll further call one (2,0) , (1,1) , (2,1) and return cost of minPath by brute Force
2)Next, it'll call on  (0,1) => which'll further call one (1,1) , (0,2) , (1,2) and return cost of minPath by brute Force
3)Finally, it'll call  (1,1) => which'll further call one (2,1) , (1,2) , (2,2) and return cost of minPath by brute Force

We can see that just for one cell (0,0), it's making recursive calls that have been already calculated by brute force
(1,1) => 3 times
(2,1) => 2 times
(1,2) => 2 times

This repeats for every single cell, ans hence time complexity increases
Let's memoize by making an array which'll store calculated minCost for every cell 
*/
/*
int helper_minCostPath(int** arr,int i,int j,int m,int n,int** output)
{
	if(i >= m || j >= n	) 	//invalid value for i or j will return INT_MAX, ie, that path will
		return INT_MAX;		//not be included while using min() function as other values will always be smaller than INT_MAX

	if(i == m-1 && j == n-1) //Base Case, path found
		return arr[i][j];	 //ie, arr[m-1][n-1]

	if(output[i][j]!=-1)
		return output[i][j];
	else
	{
		//Finding cost of paths of each move that can be made
		int pA = helper_minCostPath(arr, i + 1, j, m, n,output);	   //Moving down a row
		int pB = helper_minCostPath(arr, i, j + 1, m, n,output);	   //Moving right a column
		int pC = helper_minCostPath(arr, i + 1, j + 1, m, n,output); //Moving diagonally downwards

		output[i][j] = arr[i][j] + min(pA, min(pB, pC)); //total cost is cost of min path + value at each cell(particular position)
												 //in array which has to be included in minCostPath
		return output[i][j];
	}
}
int minCostPath(int** arr,int m,int n)
{
	int **output = new int *[m]; //Creating an array of size (m,n) & filling it with -1
	for (int i = 0; i < m; ++i)  //In this question, we don't need extra space of 1 in both row and column, like other optimization problems
	{							 
		output[i] = new int[n];
		for (int j = 0; j <n; ++j)
			output[i][j] = -1;
	}
	return helper_minCostPath(arr,0,0,m,n,output);	// starting from (0,0)
}
*/

//DP SOLUTION => BOTTOM UP APPROACH => going from (m-1,n-1) to (0,0)
int minCostPath(int **arr, int m, int n)
{
	int **output = new int *[m + 1]; //Creating an array of size (m+1,n+1)
	for (int i = 0; i <= m; ++i)
		output[i] = new int[n + 1];

	//BASE CASE FILLING IN OUTPUT ARRAY, ONE BASE CASE FILLED IN LOOP
	for (int i = 0; i <= m; ++i) //when i >= m , return INT_MAX, base case, same as recursion
		output[i][n] = INT_MAX;

	for (int j = 0; j <= n; ++j) //when j >= n , return INT_MAX, base case, same as recursion
		output[m][j] = INT_MAX;

	//SOLVING USING DP
	for (int i = m - 1; i >= 0; --i)
	{
		for (int j = n - 1; j >= 0; --j)
		{
			if (i == m - 1 && j == n - 1) //Actual base case which gets us our ans, output[m-1][n-1]=arr[m-1][n-1], same as in recursion
				output[i][j] = arr[i][j]; //We can verify this base case from memoized answer above ^
			else
			{
				int pA = output[i + 1][j];
				int pB = output[i][j + 1];
				int pC = output[i + 1][j + 1];

				output[i][j] = arr[i][j] + min(pA, min(pB, pC));
			}
		}
	}
	return output[0][0];
}

int main()
{
	int **arr, m, n;
	cin >> m >> n;
	arr = new int *[m];
	for (int i = 0; i < m; i++)
	{
		arr[i] = new int[n];
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
	cout << minCostPath(arr, m, n) << endl;
}
/*
An integer matrix of size (M x N) has been given. Find out the minimum cost to reach from the cell (0, 0) to (M - 1, N - 1).
From a cell (i, j), you can move in three directions:
1. ((i + 1),  j) which is, "down"
2. (i, (j + 1)) which is, "to the right"
3. ((i+1), (j+1)) which is, "to the diagonal"
The cost of a path is defined as the sum of each cell's values through which the route passes.
 Input format :
The first line of the test case contains two integer values, 'M' and 'N', separated by a single space. They represent the 'rows' and 'columns' respectively, for the two-dimensional array/list.

The second line onwards, the next 'M' lines or rows represent the ith row values.

Each of the ith row constitutes 'N' column values separated by a single space.
Output format :
Print the minimum cost to reach the destination.
Constraints :
1 <= M <= 10 ^ 2
1 <= N <=  10 ^ 2

Time Limit: 1 sec
Sample Input 1 :
3 4
3 4 1 2
2 1 8 9
4 7 8 1
Sample Output 1 :
13

Sample Input 2 :
3 4
10 6 9 0
-23 8 9 90
-200 0 89 200
Sample Output 2 :
76

Sample Input 3 :
5 6
9 6 0 12 90 1
2 7 8 5 78 6
1 6 0 5 10 -4 
9 6 2 -10 7 4
10 -2 0 5 5 7
Sample Output 3 :
18
*/