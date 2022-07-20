#include <iostream>
#include <string>
using namespace std;

const string kp[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
int keypad(int num,string* output)
{
    if(num==0 || num==1)
    {
        output[0]=kp[num];
        return 1;
    }
    int current=num%10;
    int smallCount=keypad(num/10,output);
    int length=kp[current].size();
    int newlen=smallCount*length;

    int k=0;
    for(int i=0;i<smallCount;++i) 
    {
        for(int j=0;j<length;++j)
        {
            output[smallCount+k]=output[i]+kp[current][j];  //Appending new strings in output itself after smallCount no of strings in output
            k++;
        }
    }
    for(int i=0;i<newlen;++i)
    output[i]=output[i+smallCount]; //Shifting newer formed strings back by smallCount to replace the now redundant, original strings

    return smallCount*length;
}

int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}


/*
Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.

Note : 1. The order of strings are not important.
2. Input and output has already been managed for you. You just have to populate the output array and return the 
count of elements populated in the output array.

Input Format :
Integer n
Output Format :
All possible strings in different lines

Constraints :
1 <= n <= 10^6

Sample Input:
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf
*/
