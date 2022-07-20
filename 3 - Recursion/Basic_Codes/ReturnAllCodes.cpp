#include <iostream>
#include<string>
using namespace std;

int codes(int num,string output[1000])
{   
    //BASE CASES
    if(num==0)
    return 0;
    if(num <= 10)
    {
        string s="";
        s.push_back('a'+num-1);
        output[0]=s;
        return 1;
    }
    if(num>10 && num<=26)
    {
        string s1="",s2="";
        s1.push_back('a'+num%10-1);
        s1.push_back('a'+num/10-1);
        s2.push_back('a'+num-1);
        output[0]=s1;
        output[1]=s2;
        return 2;
    }

    //RECURSIVE CALLS AND SMALL CALC
    int count=codes(num/10,output);
    int x=num%10,y=num%100;
    for(int i=0;i<count;++i)
    {
        string s;
        s.push_back('a'+x-1);
        output[i]+=s;
    }

    if(y <= 26)
    {
        int temp=codes(num/100,output+count);
        for(int i=count;i<count+temp;++i)
        {
            string s;
            s.push_back('a'+y-1);
            output[i]+=s;
        }
        return count+temp;
    }
    else
    {
        return count;
    }

}

int getCodes(string input, string output[1000]) 
{
    return codes(stoi(input),output);
}

int main(){
    string input;
    cin >> input;

    string output[1000];
    int count = getCodes(input, output);
    for(int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;
    return 0;
}

/*
Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. 
Write a program to return the list of all possible codes that can be generated from the given string.
Note : The order of codes are not important. And input string does not contain 0s.

Input format :
A numeric string

Constraints :
1 <= Length of String S <= 10

Sample Input:
1123
Sample Output:
aabc
kbc
alc
aaw
kw
*/