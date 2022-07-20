#include <iostream>
#include <vector>
using namespace std;

int helper(vector<vector<int>> &arr, int n, vector<vector<bool>> &visited, int i, int j);
int getBiggestPieceSize(vector<vector<int>> &arr, int n);

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> cake(n, vector<int>(n));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> cake[i][j];
        }
    }

    cout << getBiggestPieceSize(cake, n);
}

int helper(vector<vector<int>> &arr, int n, vector<vector<bool>> &visited, int i, int j)
{
    visited[i][j] = 1;
    int ans = 0;
    if (i + 1 < n)
    {
        if (arr[i + 1][j] == 1 && !visited[i + 1][j])
            ans += helper(arr, n, visited, i + 1, j);
    }
    if (i - 1 >= 0)
    {
        if (arr[i - 1][j] == 1 && !visited[i - 1][j])
            ans += helper(arr, n, visited, i - 1, j);
    }
    if (j + 1 < n)
    {
        if (arr[i][j + 1] == 1 && !visited[i][j + 1])
            ans += helper(arr, n, visited, i, j + 1);
    }
    if (j - 1 >= 0)
    {
        if (arr[i][j - 1] == 1 && !visited[i][j - 1])
            ans += helper(arr, n, visited, i, j - 1);
    }

    return ans + 1;
}
int getBiggestPieceSize(vector<vector<int>> &arr, int n)
{
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    int ans, maxSize = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (arr[i][j] == 1)
            {
                ans = helper(arr, n, visited, i, j);
                maxSize = max(ans, maxSize);
            }
        }
    }
    return maxSize;
}

/*
It's Gary's birthday today and he has ordered his favourite square cake consisting of '0's and '1's . But Gary wants the biggest piece of '1's and no '0's . A piece of cake is defined as a part which consist of only '1's, and all '1's share an edge with each other on the cake. Given the size of cake N and the cake, can you find the count of '1's in the biggest piece of '1's for Gary ?
Input Format :
The first line of input contains an integer, that denotes the value of N.
Each of the following N lines contain N space separated integers.
Output Format :
Print the count of '1's in the biggest piece of '1's, according to the description in the task.
Constraints :
1 <= N <= 1000
Time Limit: 1 sec
Sample Input 1:
2
1 1
0 1
Sample Output 1:
3
*/