#include<iostream>
using namespace std;

#include<climits>
/*
Apporach => Essentially, we have to find maxlength of common characters with same relative order in both the strings

We have 2 cases => 
1) s[0] == t[0] , in which case that character will be included in LCS
    Hence return 1 + LCS(s.substr(1),t.substr(1)); => 1 signifying the current common character which is matched

2) s[0] != t[0], in which case =>
    a) s[0] included in LCS as it might be present later in t and get matched in 1) case, t[0] is discarded, a = LCS(s.substr(1),t)
    b) s[0] is discarded, t[0] included in LCS as it might be present later in s and get matched in 1) case, b = LCS(s,t.substr(1))
    c) s[0] and t[0] are both not included in LCS as they might be unique to both strings and can't get matched, c = LCS(s.substr(1),t.substr(1))

    return max(a,max(b,c)); => ans will be the one which returns length of longest common subsequence
*/
//BRUTE FORCE SOLUTION
/*
int LCS(string s, string t)
{
    if (s.length() == 0 || t.length() == 0) //Base Case
        return 0;

    if(s[0] == t[0])
        return 1 + LCS(s.substr(1),t.substr(1));    //Match, include character by adding 1 to LCS for subtrings, and returning
    else
    {
        int a = LCS(s,t.substr(1)); //included s[0] and discard t[0], as s[0] might get matched later in t
        int b = LCS(s.substr(1),t); //included t[0] and discard s[0], as t[0] might get matched later in s
        int c = LCS(s.substr(1),t.substr(1)); //ignore both characters as they might be unique to both strings

        return max(a,max(b,c));
    }
}
*/

//MEMOIZED => TOP-DOWN APPROACH => going from beginning of each string till end of each string
/*
Need for optimization => eg, strings are s => "xyz" , t => "zxay"
s[0]!=t[0],
calls are made on ("yz","zxay") , ("xyz","xay") , ("yz","xay")
("yz","zxay") => s[0]!=t[0], calls are made on ("y","zxay"), ("yz","xay"), ("z","xay"),....
("xyz","xay") => s[0]==t[0], call is made on ("yz","ay"),...
("yz","xay")  => s[0]!=t[0], calls are made on ("z","xay"), ("yz","ay"), ("z","ay")

We see repetition of calls for ("yz","xay"), ("yz","ay") 
We'll see further repetition for more depth in recursion tree and hence complexity will become exponential
Hence we can memoize it, and also add DP
*/
/*
int helper_LCS(int **arr, string s, string t)
{
    if (s.length() == 0 || t.length() == 0) //Base Case
        return 0;

    int m = s.size(), n = t.size();
    if (arr[m][n] != -1)
        return arr[m][n];

    if (s[0] == t[0]) //Match, include character by adding 1 to LCS for subtrings, and returning
    {
        arr[m][n] = 1 + helper_LCS(arr, s.substr(1), t.substr(1));
        return arr[m][n];
    }
    else
    {
        int a = helper_LCS(arr, s, t.substr(1));           //included s[0] and discard t[0], as s[0] might get matched later in t
        int b = helper_LCS(arr, s.substr(1), t);           //included t[0] and discard s[0], as t[0] might get matched later in s
        int c = helper_LCS(arr, s.substr(1), t.substr(1)); //ignore both characters as they might be unique to both strings

        arr[m][n] = max(a, max(b, c));
        return arr[m][n];
    }
}
int LCS(string s, string t)
{
    int **arr = new int *[s.size() + 1];    //arr[s.size()][t.size()] will hold final answer
    for (int i = 0; i <= s.size(); ++i)
    {
        arr[i] = new int[t.size() + 1];
        for (int j = 0; j <= t.size(); ++j)
            arr[i][j] = -1;
    }
    return helper_LCS(arr, s, t);
}
*/

//DP SOLUTION => BOTTOM UP APPROACH => going from end of each string till start of each string, as it is bottom up approach
int LCS(string s, string t)
{
    int m = s.size(), n = t.size();
    int **arr = new int *[m + 1]; //creating an array of size (m+1,n+1) where (i,j) in array will correspond to length of subtrings
    for (int i = 0; i <= m; ++i)
        arr[i] = new int[n + 1];

    //Base Case filling
    for (int i = 0; i <= m; ++i) //Base case, if t.size() == 0, return 0
        arr[i][0] = 0; 

    for (int j = 0; j <= n; ++j) //Base case, if s.size() == 0, return 0
        arr[0][j] = 0;

    //DP Solution
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (s[m - i] == t[n - j]) //(i),(j) goes from (1),(1) to (s.size()),(t.size()), hence to access characters
            {                         //in array in reverse order(DP => bottom up), we have to use s[m-i] and t[n-j] respectively

                arr[i][j] = 1 + arr[i - 1][j - 1]; //analogous to arr[m][n] = 1 + LCS(s.substr(1),t.substr(1))
            }
            else
            {
                int a = arr[i - 1][j];     //analogous to LCS(s,t.substr(1))
                int b = arr[i][j - 1];     //analogous to LCS(s.substr(1),t)
                int c = arr[i - 1][j - 1]; //analogous to LCS(s.substr(1),t.substr(1))

                arr[i][j] = max(a, max(b, c));
            }
        }
    }
    return arr[m][n];
}
int main()
{
    string s,t;
    cin>>s>>t;
    cout<<LCS(s,t);
}
/*
Lowest Common Subsequence problem => 
Given two strings, return length of longest common subsequence
Common Subsequence => characters in both strings should be in same order, may or may not be contiguous

eg => "abcde" , "aghib" => LCS is "ab", length is 2
eg => "abcde" , "bgchdie" => LCS is "bcde", length is 4
eg => "abcde" , "aebijcde" => LCS is "abcde", length is 5

*/