#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;

BinaryTreeNode<int>* takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
#include<stack>
void zigZagOrder(BinaryTreeNode<int>* root) 
{
    if(root==NULL)
    return;

    stack<BinaryTreeNode<int>*> s1,s2;
    s1.push(root);
    while(!s1.empty() || !s2.empty())
    {
        if (!s1.empty())
        {
            while (!s1.empty())
            {
                BinaryTreeNode<int> *top = s1.top();
                s1.pop();
                if(top!=NULL)
                cout<<top->data<<" ";

                if(top->left!=NULL)
                s2.push(top->left);
                if(top->right!=NULL)
                s2.push(top->right);
            }
        }
        else
        {   
            while (!s2.empty())
            {
                BinaryTreeNode<int> *top = s2.top();
                s2.pop();
                if(top!=NULL)
                cout<<top->data<<" ";

                if(top->right!=NULL)
                s1.push(top->right);
                if(top->left!=NULL)
                s1.push(top->left);
            }
        }

        cout<<endl;
    }
    
}
int main() 
{
    BinaryTreeNode<int>* root = takeInput();
    zigZagOrder(root);
}
/*
Given a binary tree, print the zig zag order. In zigzag order, level 1 is printed from left to right, level 2 from right to left and so on. This means odd levels should get printed from left to right and even level right to left.
Input format:
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have a left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
Output Format:
The binary tree is printed level wise, as described in the task. Each level is printed in new line.
Constraints
Time Limit: 1 second

Sample Input 1:
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 1:
5
10 6
2 3

Sample Input 2:
8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
Sample Output 2:
8
10 3
1 6 14
13 7 4
*/