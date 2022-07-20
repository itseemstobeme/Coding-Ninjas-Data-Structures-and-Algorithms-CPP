#include <iostream>
using namespace std;

int staircase(int n)
{
    //Base Cases
    if(n==1)        //When n=1 stairs , 1 way of climbing stairs => {(1)}
    return 1;
    if(n==2)        //When n=2 stairs , 2 ways of climbing stairs => {(2),(1,1)}
    return 2;
    if(n==3)        //When n=3 stairs , 4 ways of climbing stairs => {(3),(1,2),(2,1),(1,1,1)}
    return 4;

    //Recursive Call
    return staircase(n-1)+staircase(n-2)+staircase(n-3); //For any n > 3
}
int main() {
    int n, output;
    cin >> n;
    output=staircase(n);
    cout<< output <<endl;
}

/*
A child is running up a staircase with N steps, and can hop either 1 step, 2 steps or 3 steps at a time. 
Implement a method to count how many possible ways the child can run up to the stairs. 
You need to return number of possible ways W.

Input format :
Integer N
Output Format :
Integer W

Constraints :
1 <= N <= 30

Sample Input 1 :
4
Sample Output 1 :
7

Sample Input 2 :
5
Sample Output 2 :
13
*/
