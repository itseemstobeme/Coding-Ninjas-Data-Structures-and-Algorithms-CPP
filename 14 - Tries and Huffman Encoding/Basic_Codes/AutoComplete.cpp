#include <iostream>
#include "Trie.h"
#include <string>
using namespace std;

void printSubTrie(TrieNode* root,string pattern,string print)
{
    if(pattern.length() == 0)       //If length of pattern is now zero, print if isTerminal is true and recursively print all subTries
    {   
        if(root->isTerminal)
        cout<<print<<endl;
        for(int i=0;i<26;++i)
        {
            if(root->children[i]!=NULL)
            printSubTrie(root->children[i],pattern,print+root->children[i]->data);
        }
        return; //very imp here as if pattern.len()==0, it does all the above ^ and goes down and tries accessing pattern[0], error will be thrown as len == 0
    }           //must return if len == 0 and all above ^ operations have been performed

    int index= pattern[0] - 'a';
    if(root->children[index]!=NULL)
    printSubTrie(root->children[index],pattern.substr(1),print+pattern[0]);
    else
    return;
}
void Trie::autoComplete(vector<string> words,string pattern)
{   
    for(int i=0;i<words.size();++i)
    insertWord(words[i]);

    printSubTrie(root,pattern,"");
}
int main() {
    Trie t;
    int n;
    cin >> n;

    vector<string> vect;

    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        vect.push_back(word);
    }

    string pattern;
    cin >> pattern;

    t.autoComplete(vect, pattern);
}
/*
Given n number of words and an incomplete word w. You need to auto-complete that word w.
That means, find and print all the possible words which can be formed using the incomplete word w.
Note : Order of words does not matter.
Input Format :
The first line of input contains an integer, that denotes the value of n.
The following line contains n space separated words.
The following line contains the word w, that has to be auto-completed.
Output Format :
Print all possible words in separate lines.
Constraints:
Time Limit: 1 sec

Sample Input 1 :
7
do dont no not note notes den
no
Sample Output 2 :
no
not
note
notes

Sample Input 2 :
7
do dont no not note notes den
de
Sample Output 2 :
den

Sample Input 3 :
7
do dont no not note notes den
nom
Sample Output 3 :
(Empty) There is no word which starts with "nom"
*/