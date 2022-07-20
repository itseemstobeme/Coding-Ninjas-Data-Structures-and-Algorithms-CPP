#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class PriorityQueue
{
    vector<int> v;

public:
    PriorityQueue()
    {
    }

    bool isEmpty()
    {
        return v.size() == 0;
    }

    int getSize()
    {
        return v.size();
    }

    int getMax()
    {
        if (isEmpty())
            return INT_MIN;
        else
            return v[0];
    }

    void insert(int element)
    {
        v.push_back(element);

        int childIndex = v.size() - 1;
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (v[childIndex] > v[parentIndex])
                swap(v[childIndex], v[parentIndex]);
            else
                break;
            childIndex = parentIndex;
        }
    }

    int removeMax()
    {
        if (isEmpty())
            return INT_MIN;
        int maximum = v[0];
        v[0] = v[v.size() - 1];
        v.pop_back();
        int parentIndex = 0;
        while (parentIndex < v.size())
        {
            int leftChild = 2 * parentIndex + 1;
            int rightChild = 2 * parentIndex + 2;
            int childIndex;
            if (rightChild < v.size())
                childIndex = v[leftChild] > v[rightChild] ? leftChild : rightChild;
            else
            {
                if (leftChild < v.size())
                    childIndex = leftChild;
                else
                    break;
            }

            if (v[parentIndex] < v[childIndex])
                swap(v[parentIndex], v[childIndex]);
            else
                break;
            parentIndex = childIndex;
        }
        return maximum;
    }
};


int main()
{
    PriorityQueue pq;
    int choice;
    cin >> choice;

    while (choice != -1)
    {
        switch (choice)
        {
        case 1: // insert
            int element;
            cin >> element;
            pq.insert(element);
            break;
        case 2: // getMax
            cout << pq.getMax() << "\n";
            break;
        case 3: // removeMax
            cout << pq.removeMax() << "\n";
            break;
        case 4: // size
            cout << pq.getSize() << "\n";
            break;
        case 5: // isEmpty
            cout << (pq.isEmpty() ? "true\n" : "false\n");
        default:
            return 0;
        }

        cin >> choice;
    }
}

/*
Implement the class for Max Priority Queue which includes following functions -
1. getSize -
Return the size of priority queue i.e. number of elements present in the priority queue.
2. isEmpty -
Check if priority queue is empty or not. Return true or false accordingly.
3. insert -
Given an element, insert that element in the priority queue at the correct position.
4. getMax -
Return the maximum element present in the priority queue without deleting. Return -Infinity if priority queue is empty.
5. removeMax -
Delete and return the maximum element present in the priority queue. Return -Infinity if priority queue is empty.

Sample Input 1 :
1 3 1 4 1 63 1 21 1 9 2 3 1 7 2 2 2 3 -1
Output 1:
63
63
21
21
21
21

Sample Input 2 :
1 3 1 4 1 63 1 21 1 9 2 3 1 7 3 4 5 -1
Output 2:
63
63
21
4
false

Sample Input 3 :
1 3 1 4 1 63 1 21 1 9 2 3 1 7 2 3 2 -1
Output 3:
63
63
21
21
9
*/