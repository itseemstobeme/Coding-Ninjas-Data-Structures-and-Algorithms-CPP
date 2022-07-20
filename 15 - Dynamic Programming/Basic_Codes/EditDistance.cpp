#include <iostream>
using namespace std;

//SIMILAR QUESTION TO LCS
//BRUTE FORCE SOLUTION
//Approach explained in comments
/*
int editDistance(string s1, string s2)
{
    if (s1.length() == 0 || s2.length() == 0) //Base Case, if 1) either of strings is empty, edit distance will be
        return max(s1.length(), s2.length()); //max of sizes of both strings, as the string which is not zero size must be either
                                              //deleted from string or appended to string with size == 0 AND
                                              //2)if both are empty strings editDistance = 0 & max(0,0) = 0,
                                              //hence base case is correct for this too

    if (s1[0] == s2[0]) //Characters are same, hence no operation req, return editDistance of substrings
        return editDistance(s1.substr(1), s2.substr(1));
    else
    {
        //Insertion OR Updation of 0th element
        int a = editDistance(s1.substr(1), s2.substr(1)); //changing either of 0th elements or inserting one element in either, to make s1[0] == s2[0]
                                                          //eg s1 = a.., s2 = b...., insert a in s2 => s1 = a.., s2 = ab... => ask recursion to bring ans for substr
                                                          //for both strings as s1[0] == s2[0], hence can be ignored now
                                                          //eg s1 = a..., s2 = b..., make s1[0] == s2[0] => s1 = b..., s2 = b... => ask recursion to bring ans for substr
                                                          //for both strings as s1[0] == s2[0], hence can be ignored now

        //Removal of element of 0th element
        int b = editDistance(s1, s2.substr(1)); // Since s1[0]!=s2[0], we can delete either 0th element from either string
        int c = editDistance(s1.substr(1), s2); // to try and make strings equal => passing substr of either string is performing that operation
                                                //as it means we're ignoring(ie, deleting) 0th element of the string it's being deleted from

        return 1 + min(a, min(b, c)); //Adding 1 indicates the operation that we're making to make strings equal
                                      //which takes minimum no of operations
    }
}
*/

//MEMOIZED => TOP DOWN APPROACH => moving in strings from 0 to s.size() or t.size()
//Need for optimization => calls same as "LCS.cpp", same optimization required
/*
int helper_ED(int **arr, string s1, string s2)
{
    int m = s1.size(), n = s2.size();

    if (m == 0 || n == 0) //Base case
        return max(m, n);

    if (arr[m][n] != -1)
        return arr[m][n];

    if (s1[0] == s2[0])
    {
        arr[m][n] = helper_ED(arr, s1.substr(1), s2.substr(1));
    }
    else
    {
        int a = helper_ED(arr, s1.substr(1), s2.substr(1));
        int b = helper_ED(arr, s1, s2.substr(1));
        int c = helper_ED(arr, s1.substr(1), s2);

        arr[m][n] = 1 + min(a, min(b, c));  //Adding 1 indicates the operation that we're making to make strings equal
                                            //which takes minimum no of operations 
    }
    return arr[m][n];
}
int editDistance(string s1, string s2)
{
    int m = s1.size(), n = s2.size();

    int **arr = new int *[m + 1];
    for (int i = 0; i <= m; ++i)
    {
        arr[i] = new int[n + 1];
        for (int j = 0; j <= n; ++j)
            arr[i][j] = -1;
    }

    return helper_ED(arr, s1, s2);
}
*/

//DP SOLUTION => moving in strings from s.size() or t.size() to 0
int editDistance(string s1, string s2)
{
    int m = s1.length(), n = s2.length();

    int **arr = new int *[m + 1]; //Creating array of size (m+1,n+1)
    for (int i = 0; i <= m; ++i)
        arr[i] = new int[n + 1];

    //Base Case Filling
    for (int i = 0; i <= m; ++i) //Base Case, if (m == 0 || n == 0) return max(m,n) => here m=0,n=i max(0,i) => i
        arr[i][0] = i;

    for (int j = 0; j <= n; ++j) //Base Case, if (m == 0 || n == 0) return max(m,n) => here m=j,n=0, max(j,0) => j
        arr[0][j] = j;

    arr[0][0] = 0; //Base Case, if (m == 0 || n == 0) return max(m,n) => when m,n=0, max(0,0) => 0

    //DP calculation
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (s1[m - i] == s2[n - j])        //DP is bottom up approach, hence moving backward in strings, from last to first
                arr[i][j] = arr[i - 1][j - 1]; //analogous to editDistance(s1.substr(1),s2.substr(1))
            else
            {
                int a = arr[i - 1][j - 1]; //analogous to editDistance(s1.substr(1),s2.substr(1))
                int b = arr[i][j - 1];     //analogous to editDistance(s1,s2.substr(1))
                int c = arr[i - 1][j];     //analogous to editDistance(s1.substr(1),s2)

                arr[i][j] = 1 + min(a, min(b, c)); //Adding 1 indicates the operation that we're making to make strings equal
                                                   //which takes minimum no of operations
            }
        }
    }
    return arr[m][n];
}
int main()
{
    string s1;
    string s2;

    cin >> s1;
    cin >> s2;

    cout << editDistance(s1, s2);
}
/*
Given two strings s and t of lengths m and n respectively, find the edit distance between the strings.
Edit Distance
Edit Distance of two strings is minimum number of operations required to make one string equal to other. In order to do so you can perform any of the following three operations only :
1. Delete a character
2. Replace a character with another one
3. Insert a character
Note
Strings don't contain spaces
Input Format :
The first line of input contains a string, that denotes the value of s. The following line contains a string, that denotes the value of t.
Output Format :
The first and only line of output contains the edit distance value between the given strings.
Constraints :
1<= m,n <= 10
Time Limit: 1 second

Sample Input 1 :
abc
dc
Sample Output 1 :
2
*/