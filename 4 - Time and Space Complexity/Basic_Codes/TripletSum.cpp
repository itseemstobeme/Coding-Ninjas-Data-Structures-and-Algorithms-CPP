#include <iostream>
#include <algorithm>
using namespace std;
int pairSum(int* arr, int n, int num);  //Finds pair with sum=num in array
int tripletSum(int* arr, int n, int num)
{
    sort(arr,arr+n);
    int count=0;
    for(int i=0;i<n;++i)
    {
        int pairsum=num-arr[i];
        count+=pairSum(arr+i+1,n-i-1,pairsum);  
    }
    return count;
}

int main()
{

		int size;
		int x;
		cin >> size;

		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}
		cin >> x;

		cout << tripletSum(input, size, x) << endl;

		delete[] input;

	return 0;
}

int pairSum(int* arr, int n, int num)
{   
    int count=0;
    int i=0,j=n-1;
    while(i<j)
    {
        
        if(arr[i]+arr[j]==num)
        {
            if(arr[i]==arr[j])      //For continuous duplicate elements which sum upto num
            {   int m=0;
                while(i!=j)
                {
                    ++m;
                    ++i;
                }
                count+=m*(m+1)/2;

            }
            else
            {
            ++count;
            --j;
            }
        }
        else
        {
            if(arr[i]+arr[j] > num)
            --j;
            else
            if(arr[i]+arr[j] < num)
            ++i;
        }

    }
    return count;
}