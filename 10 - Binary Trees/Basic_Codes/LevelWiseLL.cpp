#include <iostream>
#include <queue>
#include <vector>

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

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

void print(Node<int> *head)
{
    Node<int> *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
vector<Node<int> *> constructLinkedListForEachLevel(BinaryTreeNode<int> *root)
{
    vector<Node<int> *> ans;
    if (root == NULL)
        return ans;

    queue<BinaryTreeNode<int> *> pendingNodes; //In this problem, NULL in the queue serves as end of LL of that level
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    Node<int> *head = NULL, *tail = NULL;
    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        if (front != NULL) //ie, element must be inserted in LL
        {
            if (head == NULL) //no data in LL of that level, ie head and tail both are NULL
            {
                head = tail = new Node<int>(front->data); //head = tail
            }
            else //Some element(s) already present in LL, new node must be inserted after tail
            {
                tail->next = new Node<int>(front->data);
                tail = tail->next; //tail now points to new node,hence next new element will automatically
                                   //be inserted after current new node (ie, after tail)
            }

            if (front->left != NULL)
                pendingNodes.push(front->left);
            if (front->right != NULL)
                pendingNodes.push(front->right);
        }
        else //NULL encountered in queue, ie, end of LL of that linked list
        {
            ans.push_back(head); //add head of LL to vector
            tail->next = NULL;   //ie, end of LL
            head = tail = NULL;  //both initialized to NULL for next level iteration

            if (!pendingNodes.empty())   //if some elements are present in queue,ie next level, we need to add
                pendingNodes.push(NULL); // NULL to mark end of level, ie, end of LL
        }
    }

    return ans;
}
int main()
{
    BinaryTreeNode<int> *root = takeInput();
    vector<Node<int> *> ans = constructLinkedListForEachLevel(root);

    for (int i = 0; i < ans.size(); i++)
    {
        print(ans[i]);
    }
}

/*
Given a binary tree, write code to create a separate linked list for each level. You need to return the array which contains head of each level linked list.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
Output format :
Each level linked list is printed in new line (elements are separated by space).
Constraints:
Time Limit: 1 second

Sample Input 1:
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 1:
5 
6 10 
2 3 
9
*/