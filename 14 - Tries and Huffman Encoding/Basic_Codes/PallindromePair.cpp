#include <iostream>
#include"Trie.h"
using namespace std;

//Insert all words in Trie
//Then traverse all words[i],
// for any string, eg, ("abc"), possible pallindromic pairs for it are "cba","ba","cb", "_cba","cba_", where _ is some character
//Hence after adding all words into Trie, for a string "abc", all we need to search for is existence of "cba","ba","cb" in Trie
//This will work for all words in words[i]
#include<algorithm>
bool Trie::isPalindromePair(vector<string> words)
{
    for(int i=0;i<words.size();++i)
        insertWord(words[i]);

    for(int i=0;i<words.size();++i)
    {
        string rev=words[i];
        reverse(rev.begin(),rev.end());

        if(searchWord(rev)) return true;
        else
        if(searchWord(rev.substr(1))) return true;
        else
        if(searchWord(rev.substr(0,rev.size()-1))) return true;
    }
    return false;   //will be reached if no pallindrome pair exists
}
int main() {
    Trie t;
    int n;
    cin >> n;
    vector<string> words(n);

    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }

    cout << (t.isPalindromePair(words) ? "true" : "false");
}
/*
Given 'n' number of words, you need to find if there exist any two words which can be joined to make a palindrome or any word, which itself is a palindrome.
The function should return either true or false. You don't have to print anything.
Input Format :
The first line of the test case contains an integer value denoting 'n'.

The following contains 'n' number of words each separated by a single space.
Output Format :
The first and only line of output contains true if the conditions described in the task are met and false otherwise.
Constraints:
0 <= n <= 10^5
Time Limit: 1 sec

Sample Input 1 :
4
abc def ghi cba
Sample Output 1 :
true
Explanation of Sample Input 1:
"abc" and "cba" forms a palindrome

Sample Input 2 :
2
abc def
Sample Output 2 :
false
Explanation of Sample Input 2:
Neither their exists a pair which forms a palindrome, nor any of the words is a palindrome in itself. Hence, the output is 'false.'
*/