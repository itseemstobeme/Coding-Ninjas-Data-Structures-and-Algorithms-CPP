#include <iostream>
using namespace std;

#include <unordered_map>
int pairSum(int arr[], int n)
{
    unordered_map<int, int> map; // <value,count>
    for (int i = 0; i < n; ++i)
        ++map[arr[i]];

    int count = 0;
    for (int i = 0; i < n; ++i)
    {
        int freq1 = map[arr[i]];
        int freq2 = map[-1 * arr[i]];
        if (arr[i] == 0) //If element is 0, count is n*(n-1)/2
        {
            count += (freq1 * (freq1 - 1)) / 2;
            map.erase(arr[i]);
        }
        else if (freq2 != 0)
        {
            count += freq1 * freq2; //count will be number of combos of arr[i] and -1*arr[i] , ie, freq1*freq2
            map.erase(arr[i]);
            map.erase(-1 * arr[i]);
        }
    }
    return count;
}
int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << pairSum(arr, n);

    delete[] arr;
}
/*
Given a random integer array A of size N. Find and print the count of pair of elements in the array which sum up to 0.
Note: Array A can contain duplicate elements as well.
Input format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.
Output format :
The first and only line of output contains the count of pair of elements in the array which sum up to 0. 
Constraints :
0 <= N <= 10^4
Time Limit: 1 sec

Sample Input 1:
5
2 1 -2 2 3
Sample Output 1:
2
*/