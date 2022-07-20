#include<iostream>
using namespace std;

void qsort(int* arr,int start,int end);
void quicksort(int* arr,int n);
int main()
{
    int n;
    cin>>n;
    int* arr=new int[n];
    for(int i=0;i<n;++i)
    cin>>arr[i];
    quicksort(arr,n);
    for(int i=0;i<n;++i)
    cout<<arr[i]<<" ";
}


void quicksort(int* arr,int n)
{
    qsort(arr,0,n-1);
}
void qsort(int* arr,int start,int end)
{
    if(start >= end)    //Base Case => 0 or singleton element array
    return;
    int i=start+1,j=end;
    while(i<=j)
    {
        if(arr[i] > arr[start])
        {
            if(arr[start] > arr[j])
            {
            swap(arr[i],arr[j]);

            }
            else
            j--;
        }
        else
        i++;
    }
    swap(arr[start],arr[j]);
    qsort(arr,start,j-1);
    qsort(arr,j+1,end);
}