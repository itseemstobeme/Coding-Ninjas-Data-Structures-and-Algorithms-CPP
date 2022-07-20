#include<iostream>
#include<stdlib.h>
#include "Trie.h"
using namespace std;

int main()
{
    int n;
    string word;
    Trie demoTrie;
    while(true)
    {   
        cin>>n;
        cin>>word;
        switch(n)
        {
           case 1 : demoTrie.insertWord(word); break;
           case 2 : demoTrie.searchWord(word) ? cout<<word <<" exists"<<endl :cout<<word <<" doesn't exist"<<endl ; break;
           case 3 : demoTrie.removeWord(word); break;
           case 4 : exit(0); 
           default : break;
        }
    }
}