#include <iostream>
using namespace std;

#include <unordered_map>
int highestFrequency(int *arr, int n)
{
    unordered_map<int, int> map; // <value,frequency>
    for (int i = 0; i < n; ++i)
        ++map[arr[i]];

    int maxFreqNumber = arr[0], maxFreq = map[arr[0]];
    for (int i = 1; i < n; ++i)
    {
        if (map[arr[i]] > maxFreq) //Only if frequency is greater than current
        {                          //if freq is same, not changing anything as ealier number has to be returned in that case
            maxFreq = map[arr[i]];
            maxFreqNumber = arr[i];
        }
    }
    return maxFreqNumber;
}
int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    cout << highestFrequency(arr, n);

    delete[] arr;
}
/*
You are given an array of integers that contain numbers in random order. Write a program to find and return the number which occurs the maximum times in the given input.
If two or more elements contend for the maximum frequency, return the element which occurs in the array first.
Input Format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.
Output Format :
The first and only line of output contains most frequent element in the given array.
Constraints:
0 <= N <= 10^8
Time Limit: 1 sec

Sample Input 1 :
13
2 12 2 11 12 2 1 2 2 11 12 2 6 
Sample Output 1 :
2

Sample Input 2 :
3
1 4 5
Sample Output 2 :
1
*/