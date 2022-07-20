#include <iostream>
#include <queue>

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
    ~BinaryTreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

using namespace std;

BinaryTreeNode<int> *takeInput()
{
    int rootData;

    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1)
        {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1)
        {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
#include <climits>
class lar
{
public:
    int maximum, minimum, height;
    bool isBST;
    lar(int maximum = INT_MIN, int minimum = INT_MAX, int height = 0, bool isBST = true)
        : maximum(maximum), minimum(minimum), height(height), isBST(isBST)
    {
    }
};
lar largestBST(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        lar ans;
        return ans;
    }

    lar left = largestBST(root->left);
    lar right = largestBST(root->right);

    int maximum, minimum, height;
    bool isBST;
    maximum = max(root->data, max(left.maximum, right.maximum));
    minimum = min(root->data, min(left.minimum, right.minimum));
    isBST = (root->data > left.maximum) && (root->data <= right.minimum) && left.isBST && right.isBST;
    if (isBST)
        height = 1 + max(left.height, right.height);
    else
        height = max(left.height, right.height);

    lar ans(maximum, minimum, height, isBST);
    return ans;
}
int largestBSTSubtree(BinaryTreeNode<int> *root)
{
    return largestBST(root).height;
}
int main()
{
    BinaryTreeNode<int> *root = takeInput();
    cout << largestBSTSubtree(root);
    delete root;
}

/*
Given a Binary tree, find the largest BST subtree. That is, you need to find the BST with maximum height in the given binary tree. You have to return the height of largest BST.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
Output format:
The first and only line of output contains the height of the largest BST.
Constraints:
Time Limit: 1 second

Sample Input 1:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 1:
2


*/