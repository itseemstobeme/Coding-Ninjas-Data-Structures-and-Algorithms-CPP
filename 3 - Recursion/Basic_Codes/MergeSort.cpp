/*
Code for Merge Sort
*/
#include<iostream>
using namespace std;

void merge(int* arr,int start,int end);
void msort(int* arr,int start,int end);
void mergesort(int* arr,int n);

int main()
{
    int n;
    cin>>n;
    int* arr=new int[n];
    for(int i=0;i<n;++i)
    cin>>arr[i];
    mergesort(arr,n);
    for(int i=0;i<n;++i)
    cout<<arr[i]<<" ";
}


void mergesort(int* arr,int n)
{
    msort(arr,0,n-1);
}
void msort(int* arr,int start,int end)
{
    if(start >= end)
    return;
    int mid=(start+end+1)/2;
    msort(arr,start,mid-1);
    msort(arr,mid,end);
    merge(arr,start,end);
}
void merge(int* arr,int start,int end)
{
    int mid=(start+end+1)/2;
    int n=end-start+1;
    int* c =new int[n];

    int i=start,j=mid;
    int k=0;
    while(i<mid && j<end+1 && k<n)
    {
        if(arr[i] < arr[j])
        c[k++]=arr[i++];
        else
        {
            if(arr[i] > arr[j])
            c[k++]=arr[j++];
            else
            {
                c[k++]=arr[i++];
                c[k++]=arr[j++];
            }
        }

    }

    while(i < mid)
    c[k++]=arr[i++];

    while(j < end+1)
    c[k++]=arr[j++];

    for(i=start,k=0;i<=end,k<n;++i,++k)
    arr[i]=c[k];

    delete[] c;
}