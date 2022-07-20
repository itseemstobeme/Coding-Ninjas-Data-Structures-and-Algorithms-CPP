#include <iostream>
#include <queue>
using namespace std;
// -1 for no child
template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

BinaryTreeNode<int> *inputLevelWise();
void printLevelWise(BinaryTreeNode<int> *root);
int main()
{
    BinaryTreeNode<int> *root = inputLevelWise();
    printLevelWise(root);
}

BinaryTreeNode<int> *inputLevelWise()
{
    int rootData;
    cin >> rootData;
    if (rootData == -1)
        return NULL;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);

    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int> *current = pendingNodes.front();
        pendingNodes.pop();

        int leftData, rightData;
        cin >> leftData;
        if (leftData != -1)
        {
            current->left = new BinaryTreeNode<int>(leftData);
            pendingNodes.push(current->left);
        }
        cin >> rightData;
        if (rightData != -1)
        {
            current->right = new BinaryTreeNode<int>(rightData);
            pendingNodes.push(current->right);
        }
    }
    return root;
}
void printLevelWise(BinaryTreeNode<int> *root)
{
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int> *current = pendingNodes.front();
        pendingNodes.pop();
        cout << current->data << ":";
        if (current->left != NULL)
        {
            cout << "L:" << current->left->data << ",";
            pendingNodes.push(current->left);
        }
        else
            cout << "L:-1;";

        if (current->right != NULL)
        {
            cout << "R:" << current->right->data;
            pendingNodes.push(current->right);
        }
        else
            cout << "R:-1";

        cout << endl;
    }
}

/*
For a given a Binary Tree of type integer, print the complete information of every node, when traversed in a level-order fashion.
To print the information of a node with data D, you need to follow the exact format :

           D:L:X,R:Y

Where D is the data of a node present in the binary tree. 
X and Y are the values of the left(L) and right(R) child of the node.
Print -1 if the child doesn't exist.


For the above depicted Binary Tree, the level order travel will be printed as followed:

1:L:2,R:3
2:L:4:,R:-1
3:L:5:,R:6
4:L:-1:,R:7
5:L:-1:,R:-1    
6:L:-1:,R:-1
7:L:-1:,R:-1

Note: There is no space in between while printing the information for each node.
Input Format:
The first and the only line of input will contain the node data, all separated by a single space. Since -1 is used as an indication whether the left or right node data exist for root, it will not be a part of the node data.
Output Format:
Information of all the nodes in the Binary Tree will be printed on a different line where each node will follow a format of D:L:X,R:Y, without any spaces in between.
Constraints:
1 <= N <= 10^5
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec

Sample Input 1:
8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
Sample Output 1:
8:L:3,R:10
3:L:1,R:6
10:L:-1,R:14
1:L:-1,R:-1
6:L:4,R:7
14:L:13,R:-1
4:L:-1,R:-1
7:L:-1,R:-1
13:L:-1,R:-1

Sample Input 2:
1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
Sample Output 2:
1:L:2,R:3
2:L:4,R:5
3:L:6,R:7
4:L:-1,R:-1
5:L:-1,R:-1
6:L:-1,R:-1
7:L:-1,R:-1
*/