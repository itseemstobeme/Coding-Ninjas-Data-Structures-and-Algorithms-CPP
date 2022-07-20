#include <iostream>
#include"Trie.h"
#include <string>
using namespace std;

//For pattern matching using a Trie,we need to make sure each substring of strings given in vector
//must exist in the Trie
//eg, while inserting a string "henry", the strings that will be inserted in the trie will be 
// "henry","enry","nry","ry" & "y" and make another helper search function that doesn't return isTerminal 
//but returns true if word.length()==0, ie, even if terminal is marked as false, it'll return true if pattern exists
//in any subtree
bool searchPattern(TrieNode* root,string pattern)   //helper function, just returns true instead of isTerminal in base case
{   
    if(pattern.length() == 0) return true;  //returns true instead of traditional isTerminal

    int index = pattern[0] - 'a';

    if(root->children[index]!=NULL)
     return searchPattern(root->children[index],pattern.substr(1));
    else
    return false;                           //index is NULL and pattern.length()!=0, hence pattern doesn't exist
}
bool Trie::patternMatching(vector<string> vect,string pattern)
{
    for(int i=0;i<vect.size();++i)
    {
        string s=vect[i];
        for(int j=0;j<s.size();++j)
            insertWord(s.substr(j));  //patternMatching() called using Trie object, ie, will call insertWord of the same Trie object
    }
    return searchPattern(root,pattern);
}
int main() {
    Trie t;
    int n;
    cin >> n;
    string pattern;
    vector<string> vect;

    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        vect.push_back(word);
    }
    cin >> pattern;

    cout << (t.patternMatching(vect, pattern) ? "true" : "false");
}
/*
Given a list of n words and a pattern p that we want to search. Check if the pattern p is present the given words or not. Return true if the pattern is present and false otherwise.
Input Format :
The first line of input contains an integer, that denotes the value of n.
The following line contains n space separated words.
The following line contains a string, that denotes the value of the pattern p.
Output Format :
The first and only line of output contains true if the pattern is present and false otherwise.
Constraints:
Time Limit: 1 sec

Sample Input 1 :
4
abc def ghi cba
de
Sample Output 2 :
true

Sample Input 2 :
4
abc def ghi hg
hi
Sample Output 2 :
true

Sample Input 3 :
4
abc def ghi hg
hif
Sample Output 3 :
false
*/