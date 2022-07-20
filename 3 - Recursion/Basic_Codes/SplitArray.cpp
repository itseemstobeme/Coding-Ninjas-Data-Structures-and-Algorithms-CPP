
#include <iostream>
using namespace std;

bool check(int* arr, int n, int current, int lsum, int rsum) 
{
    if(current==n)            //After final element added to either sides, checking if lsum==rsum
    return lsum==rsum;        //Size of array is N+1, hence current==n implies final position in array which has garbage(irrelevant to us)

    if(arr[current]%5==0)
    lsum+=arr[current];       //If divisible by 5, add to leftsum        
    else
    if(arr[current]%3==0)     //If divisible by 3 but not by 5, add to rightsum
    rsum+=arr[current];
    else
    return 
    check(arr,n,current+1,lsum+arr[current],rsum) || check(arr,n,current+1,lsum,rsum+arr[current]);
    //If not divisible by either, check ans when current element added to either lsum or rsum
}
bool splitArray(int* input,int size)
{
    return check(input,size,0,0,0);
}
int main() {

	int size;
	cin>>size;
	int *input=new int[size+1];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	
    if(splitArray(input, size)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
	return 0;
}

/*
Given an integer array A of size N, check if the input array can be splitted in two parts such that -
- Sum of both parts is equal
- All elements in the input, which are divisible by 5 should be in same group.
- All elements in the input, which are divisible by 3 (but not divisible by 5) should be in other group.
- Elements which are neither divisible by 5 nor by 3, can be put in any group.
Groups can be made with any set of elements, i.e. elements need not to be continuous. And you need to consider each and every element of input array in some group.
Return true, if array can be split according to the above rules, else return false.
Note : You will get marks only if all the test cases are passed.

Input Format :
Line 1 : Integer N (size of array)
Line 2 : Array A elements (separated by space)
Output Format :
true or false

Constraints :
1 <= N <= 50

Sample Input 1 :
2
1 2
Sample Output 1 :
false

Sample Input 2 :
3
1 4 3
Sample Output 2 :
true
*/