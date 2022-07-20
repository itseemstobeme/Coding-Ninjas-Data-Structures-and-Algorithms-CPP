#include <iostream>
using namespace std;

//Difference K has to be absolute
// ie for a given number A and pair sum k, we need to find x in array which satisfies the equation =>
// |A - x| = k ==> (A - x = (+-)k) ==> (x = A - k , x = A + k)
#include <unordered_map>
int getPairsWithDifferenceK(int *arr, int n, int k)
{
    unordered_map<int, int> map; // <value,count>

    for (int i = 0; i < n; ++i) // counting occurences of value at ith position in array
        ++map[arr[i]];

    unordered_map<int, int>::iterator it = map.begin();
    int pairCount = 0;
    while (it != map.end())
    {
        int value = it->first;
        int count = it->second;
        if (k == 0) // ie, combinations with same number
        {
            pairCount += (count * (count - 1)) / 2;
        }
        else
        {
            int value1 = value - k, count1 = 0;
            int value2 = value + k, count2 = 0;
            unordered_map<int, int>::iterator it1 = map.find(value1);
            unordered_map<int, int>::iterator it2 = map.find(value2);
            if (it1 != map.end())
            {
                count1 = it1->second;
            }

            if (it2 != map.end())
            {
                count2 = it2->second;
            }
            pairCount += (count * count1) + (count * count2); //count will be no of combinations current element
        }                                                     //have with the found elements which satisfy |A-x| = k
        unordered_map<int, int>::iterator temp = it;
        ++it;
        map.erase(temp);
    }
    return pairCount;
}
int main()
{
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    int k;
    cin >> k;

    cout << getPairsWithDifferenceK(input, n, k);

    delete[] input;
}
/*
You are given with an array of integers and an integer K. You have to find and print the count of all such pairs which have difference K.
Note: Take absolute difference between the elements of the array.
Input Format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol n.
The following line contains n space separated integers, that denote the value of the elements of the array.
The following line contains an integer, that denotes the value of K.
Output format :
The first and only line of output contains count of all such pairs which have an absolute difference of K. 
Constraints :
0 <= n <= 10^4
Time Limit: 1 sec

Sample Input 1 :
4 
5 1 2 4
3
Sample Output 1 :
2

Sample Input 2 :
4
4 4 4 4 
0
Sample Output 2 :
6
*/