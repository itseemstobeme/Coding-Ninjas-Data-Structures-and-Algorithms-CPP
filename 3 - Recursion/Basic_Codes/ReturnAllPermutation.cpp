#include <iostream>
#include <string>
using namespace std;


int returnPermutations(string input, string* output) 
{
    if(input == "")
    return 0;

    if(input.size()==1)     
    {
        output[0]=input[0];
        return 1;
    }
    int count=0;
    for(int i=0;i<input.size();++i)
    {
        string s1=input.substr(i+1);                        //Constructing the string with all characters
        string s2=input.substr(0,input.size()-s1.size()-1); //except ith(current) character
        int temp=returnPermutations(s2+s1,output+count);    //Returns no of permutations of each substring with ith character excluded
        for(int j=count;j<count+temp;++j)
        output[j]=input[i]+output[j];           //Loop adds excluded characters to all valid permutations in range in output array 

        count+=temp;       //Total no of new permutations=earlier permutations + newer permmutations
    }
    return count;
}

int main(){
    string input;
    cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
}

/*
Given a string S, find and return all the possible permutations of the input string.
Note 1 : The order of permutations is not important.
Note 2 : If original string contains duplicate characters, permutations will also be duplicates.

Input Format :
String S
Output Format :
All permutations (in different lines)

Sample Input :
abc
Sample Output :
abc
acb
bac
bca
cab
cba
*/