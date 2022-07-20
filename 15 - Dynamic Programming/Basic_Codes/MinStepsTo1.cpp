#include <iostream>
#include <climits>

using namespace std;

//Brute Force Recursive
/*
int countMinStepsToOne(int n)
{
    if (n == 1)     //Base case, no operations req to get from 1 -> 1
        return 0;

    int a = INT_MAX, b = INT_MAX, c = INT_MAX;
    a = countMinStepsToOne(n - 1);
    if (n % 2 == 0)
        b = countMinStepsToOne(n / 2);
    if (n % 3 == 0)
        c = countMinStepsToOne(n / 3);

    return 1 + min(a, min(b, c));   //Adding 1 to indicate the operation performed with min cost(either n-1,n/2 or n/3)
}
*/

//MEMOIZED
/*
int helper_count(int arr[],int n)
{
    if(n == 1) return 0; //Base case, no operations req to get from 1 -> 1

    if(arr[n]!=-1)
    return arr[n];
    else
    {
        int a, b=INT_MAX,c=INT_MAX;
        
        a=helper_count(arr,n-1);
        if(n%2 == 0) 
        b=helper_count(arr,n/2);
        if(n%3 == 0) 
        c=helper_count(arr,n/3);

        arr[n]= 1 + min(a,min(b,c)); //Adding 1 to indicate the operation performed with min cost(either n-1,n/2 or n/3)
        return arr[n];
    }
}
int countMinStepsToOne(int n)
{
    int* arr=new int[n+1];

    for(int i=0;i<n+1;++i)
    arr[i]=-1;

    return helper_count(arr,n);
}
*/

//DP SOLUTION
int countMinStepsToOne(int n)
{
    int *arr = new int[n + 1];

    arr[1] = 0; //Base Case

    for (int i = 2; i <= n; ++i)
    {
        int a, b = INT_MAX, c = INT_MAX;

        a = arr[i - 1];

        if (i % 2 == 0)
            b = arr[i / 2];

        if (i % 3 == 0)
            c = arr[i / 3];

        arr[i] = 1 + min(a, min(b, c)); //Adding 1 to indicate the operation performed with min cost(either n-1,n/2 or n/3)
    }
    return arr[n];
}
int main()
{
    int n;
    cin >> n;
    cout << countMinStepsToOne(n);
}
/*
Given a positive integer 'n', find and return the minimum number of steps that 'n' has to take to get reduced to 1. You can perform any one of the following 3 steps:
1.) Subtract 1 from it. (n = n - ­1) ,
2.) If its divisible by 2, divide by 2.( if n % 2 == 0, then n = n / 2 ) ,
3.) If its divisible by 3, divide by 3. (if n % 3 == 0, then n = n / 3 ).  
Input format :
The first and the only line of input contains an integer value, 'n'.
Output format :
Print the minimum number of steps.
Constraints :
1 <= n <= 200

Time Limit: 1 sec
Sample Input 1 :
4
Sample Output 1 :
2 
Explanation of Sample Output 1 :
For n = 4
Step 1 :  n = 4 / 2  = 2
Step 2 : n = 2 / 2  =  1 

Sample Input 2 :
7
Sample Output 2 :
3
Explanation of Sample Output 2 :
For n = 7
Step 1 :  n = 7 ­- 1 = 6
Step 2 : n = 6  / 3 = 2 
Step 3 : n = 2 / 2 = 1  
*/