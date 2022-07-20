#include<iostream>
using namespace std;


int bsearch(int* arr,int start,int end,int ele)
{
    if(start >end)  //Base Case
    return -1;

    if(start==end)  //Small Calculation
    {
        if(arr[start]==ele)
        return start;
        else
        return -1;
    }

    int mid=(start+end+1)/2;
    if(arr[mid]==ele)
    return mid;
    else
    {
        if(ele < arr[mid])
        return bsearch(arr,start,mid-1,ele);    //Recursive Calls
        else
        return bsearch(arr,mid+1,end,ele);
    }
}
int binarysearch(int* arr,int n,int element)
{
    return bsearch(arr,0,n-1,element);
}

int main()
{
    int n,element;
    cin>>n;
    int* input=new int[n];
    
    for(int i=0;i<n;++i)
    cin>>input[i];
    
    cin>>element;
    cout<<binarysearch(input,n,element);
    delete[] input;
}