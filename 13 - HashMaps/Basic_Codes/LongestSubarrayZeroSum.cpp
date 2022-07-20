#include <iostream>
using namespace std;

/*
Same solution as below, implemented a little simply
#include<unordere_map>
#include<climits>
int lengthOfLongestSubsetWithZeroSum(int* arr, int n) 
{
    int len = INT_MIN;
    int sum = 0;
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (map.find(sum) == map.end())
        {
            map[sum] = i;
        }
        else
        {
            if (i - map[sum] > len)
            {
                len = i - map[sum] ;
                
            }
        }
        if (sum == 0)
            len = i + 1;
    }
 
    return len;
}
*/
//Combination of PrefixSum and Hashmap
//Calculate PrefixSum and store it in array presum[]
//For some i and j positions in array, if presum[i] == presum[j], count of subarray with sum 0 will be (j-i) {j > i}
//We might need to do this multiple times as their may be multiple subarrays, subarray with max count is ans
//This checking of existence of presum[i] == presum[j] can be done easily in O(1) using a map
// eg, let array be [95, -97, -387, -435, -5, -70, 897, 127]
//presum array will be [0,95, -2, -389, -824, -829, -899, -2, 125]
//Clearly -2 exists at 2 and 7, hence length = (7-2) = 5
//Approach = > presum[] first, then iterate over presum[j] and if same exists in unordered_map<int,int> at i,
//1) maxLen = max(maxLen,j - map.find(presum[i])->second)
//2)else add <presum[j],true> in case that value appears in presum[] at later point,
//ie, that's when the ealier condition 1 will happen
#include <unordered_map>
int lengthOfLongestSubsetWithZeroSum(int *arr, int n)
{
    if (n == 0)
        return 0;

    unordered_map<int, int> map; //<value,position>
    int *presum = new int[n + 1];
    presum[0] = 0;
    for (int i = 1; i < n + 1; ++i) //making our presum[] array
        presum[i] = presum[i - 1] + arr[i - 1];

    int maxLen = 0;
    for (int i = 0; i < n + 1; ++i)
    {
        auto it = map.find(presum[i]);
        if (it != map.end())             //not updating <value,position> for current value as it already exists in map
        {                                //and if for a future position, same value exits, we need the earlier position to get longer subarray size
            int x = it->second;          // eg for [95 -97 -387 -435 -5 -70 897 -387 -435 -5 -70 897 127]
            int y = i;                   //presum = [0,95, -2, -389, -824, -829, -899, -2,-389, -824, -829, -899, -2, 125 ]
            maxLen = max(maxLen, y - x); //initially <-2,2> will be marked, when -2 is found at 7, map.find(-2) = 2, maxLen=(7-2) = 5, not marking current <-2,7> in map
                                         //next -2 will be at 12,map.find(-2)  is still = 2, maxLen = (12-2) = 10, correct ans, still not marking current <-2,12> in map
        }
        else
            map[presum[i]] = i; //marking <value,position> for future comparison
    }
    return maxLen;
}

int main()
{
    int size;
    cin >> size;

    int *arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << lengthOfLongestSubsetWithZeroSum(arr, size);

    delete[] arr;
}
/*
Given an array consisting of positive and negative integers, find the length of the longest subarray whose sum is zero.
Input Format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.
Output Format
The first and only line of output contains length of the longest subarray whose sum is zero.
Constraints:
0 <= N <= 10^8
Time Limit: 1 sec

Sample Input 1:
10 
95 -97 -387 -435 -5 -70 897 127 23 284
Sample Output 1:
5
Explanation:
The five elements that form the longest subarray that sum up to zero are: -387, -435, -5, -70, 897 
*/