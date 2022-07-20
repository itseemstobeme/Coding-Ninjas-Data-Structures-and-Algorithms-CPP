#include<iostream>
#include<vector>
using namespace std;

class TrieNode
{
    public:
    char data;           //stores character at Node
    TrieNode** children; //array which stores addresses of it's children
    bool isTerminal;     //if the Node is the terminating character of a word or not, true if it is

    //Constructor
    TrieNode(char data)
    {
        this->data=data;
        children = new TrieNode*[26];
        for(int i=0;i<26;++i)
        children[i] = NULL;   //No children initially
        isTerminal=false;
    }
};
class Trie
{
    public:
    TrieNode *root;     //root which will have no data, ie, '\0'

    //Constructor
    Trie()
    {
        root=new TrieNode('\0');
    }

    //In all the following functions, we will not deal with original root but with all its following children
    //as it is '\0'(taken as root)

    void insertWord(TrieNode* root,string word);//helper function to help make recursive calls
    void insertWord(string word);               //for user

    bool searchWord(TrieNode* root,string word);//helper function to help make recursive calls
    bool searchWord(string word);               //for user
    
    void removeWord(TrieNode* root,string word);//helper function to help make recursive calls
    void removeWord(string word);               //for user

    bool patternMatching(vector<string> vect,string pattern); //implemented as a question in PatternMatching.cpp
    bool isPalindromePair(vector<string> words); //implemented as a question in PallindromePair.cpp
    void autoComplete(vector<string> vect,string pattern); //implemented as a question in AutoComplete.cpp
};

//INSERTION OF WORD INTO TRIE
void Trie::insertWord(TrieNode* root,string word)
{
    if(word.length() == 0)            //Base Case when final letter is already explored, mark it's isTerminal as true and return
    {
        root->isTerminal=true;
        return;
    }

    int index = word[0] - 'a';
    if(root->children[index] == NULL) //If childIndex is NULL, insert child Node and call recursion on the child Node 
    {
        root->children[index]=new TrieNode(word[0]);
        insertWord(root->children[index],word.substr(1));
    }
    else
        insertWord(root->children[index],word.substr(1));   //If childIndex is not NULL, simply call recursion on childIndex
}
void Trie::insertWord(string word)
{
    insertWord(root,word); //root => current calling object's root, ie, root of current Trie
}

//SEARCHING FOR A WORD IN TRIE
bool Trie::searchWord(TrieNode* root,string word)
{
    if(word.length()==0)      //Base case, when length of word is zero, all we have to return is 'isTerminal'
    {                       //because even though wordLen=0 which means it has been found, we need to make sure it is a terminating character 
        return root->isTerminal; 
    }

    int index = word[0] - 'a';
    if(root->children[index] != NULL)   //index exists as is not NULL
    return searchWord(root->children[index],word.substr(1));
    else
    return false;                       //index doesn't exist as it is NULL
}    
bool Trie::searchWord(string word)
{   
    if(root!=NULL)              //root => current calling object's root, ie, root of current Trie
    return searchWord(root,word);
    else
    return false;
}

//DELETION OF A WORD FROM TRIE
void Trie::removeWord(TrieNode* root,string word)
{
    if(word.length() == 0)      //If word has been found, ie Len=0, unmark it and return, word will no longer show up in searching
    {
        root->isTerminal=false;  
        return;      
    }

    int index = word[0] - 'a';
    if(root->children[index]!=NULL) //character exists
    removeWord(root->children[index],word.substr(1));
    else
    return;                         //character doesn't exist

    //If this area is ever encountered, it means it comes after calling removeWord(root->children[index],word.substr(1))
    //which means the word might've existed in Trie, and its isTerminal is now false
    //Now if that childNode(root->children[index]) doesn't have any other characters as children in it
    //, ie, is marked completely with NULL(for every i, root->children[index]->children[i]=NULL) && root->children[index]->isTerminal ==false,
    //it means that the childNode doesn't have any words branching out from it and it itself isn't terminal of any word, ie, it is useless
    //Hence if it is useless, we must remove it as it has no use and might increase time complexity as
    //if we search for the same/similar word as it will go down the entire Trie path and will ultimately return isTerminal(now false) at the end
    //which means that it is useless
    //Hence,check if all children of childNode are NULL and isTerminal of childNode is false, ie, not terminal of any word  
    //and then delete it, otherwise simply return earlier
    TrieNode* childNode=root->children[index];
    if(childNode->isTerminal == false)  //not terminal of any word
    {
        for(int i=0;i<26;++i)
        {
            if(childNode->children[i] != NULL)  //not null, ie, branches into other word(s), in which case simply return   
            return;
        }
    }
    else
    return; //childNode->isTerminal is true, ie, it is terminal for some word even if might not have any further children

    //Now that we've reached here, it's established that childNode is useless
    //Simply delete it and make root->children[i] = NULL to indicate absence of now deleted character
    delete childNode;
    root->children[index]=NULL;
}   
void Trie::removeWord(string word)
{
    removeWord(root,word);  //root => current calling object's root, ie, root of current Trie
}               
