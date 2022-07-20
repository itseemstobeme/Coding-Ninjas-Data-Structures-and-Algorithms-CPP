#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode() {
        if (left) delete left;
        if (right) delete right;
    }
};

using namespace std;

BinaryTreeNode<int> *takeInput() {
    int rootData;

    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void printLevelATNewLine(BinaryTreeNode<int> *root) {
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        BinaryTreeNode<int> *first = q.front();
        q.pop();
        if (first == NULL) {
            if (q.empty()) {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        if (first->left != NULL) {
            q.push(first->left);
        }
        if (first->right != NULL) {
            q.push(first->right);
        }
    }
}
/*
We can solve it using vector/array, time and space complexity = O(n). For improved space complexity => O(logn), we use two stacks
One stack traverses in inorder fashion iteratively, ie, L->N->R, other stack traverses in {REVERSE INORDER}, ie, R->N->L
Recursion involves stack, but here since we need to move in both directions, we use a stack explicitly
The reason we do this is,since it is a BST
, one stack travels to extreme left first(hence will have the smallest elements in sorted order,smallest being on top),
 and other travels to extreme rights(hence will have the largest elements in sorted order,largest element being on top)
In this manner, top of stack1 will have smallest element, and top of stack2 will have largest element req to add upto sum
It's the same traversal as in array, but instead of using all elements(O(n)), we use O(logn) elements at most, at any instant

If it doesn't add up, we pop top of either stack depending upon sum of top elements
(if TOPstack1 + TOPstack2 > SUM), stack2.pop => similar to --j in array pair sum method
(if TOPstack1 + TOPstack2 < SUM), stack1.pop => similar to ++i in array pair sum method
(if TOPstack1 + TOPstack2 == SUM) & print, stack1.pop && stack2.pop => similar to ++i,--j in array pair sum method

Since it is going to extremes in either direction, max it can travel is height, ie, max space in either stack => O(h) => O(logn)
Hence, space complexity will be O(logn) in this method
Time complexity will still be O(n), as we are going to each node and comparing, similar to array method
*/
/*
Time complexity: O(N)
Space complexity: O(H)
where N is the number of nodes in the input BST
and H is the height of the input BST
*/
#include <stack>
int countNodes(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return countNodes(root->left) + countNodes(root->right) + 1;
}
void printNodesSumToS(BinaryTreeNode<int> *root, int s)
{
    if (root == NULL)
    {
        return;
    }
    int totalCount = countNodes(root);
    int count = 0;
    stack<BinaryTreeNode<int> *> inorder;
    stack<BinaryTreeNode<int> *> revInorder;
    BinaryTreeNode<int> *currentNode = root;
    while (currentNode != NULL)
    {
        inorder.push(currentNode);
        currentNode = currentNode->left;
    }
    currentNode = root;
    while (currentNode != NULL)
    {
        revInorder.push(currentNode);
        currentNode = currentNode->right;
    }
    while (count < totalCount - 1)
    {
        BinaryTreeNode<int> *inorderTop = inorder.top();
        BinaryTreeNode<int> *revInorderTop = revInorder.top();
        if (inorderTop->data + revInorderTop->data == s)
        {
            cout << inorderTop->data << " " << revInorderTop->data << endl;
            BinaryTreeNode<int> *top = inorderTop;
            inorder.pop();
            count++;
            if (top->right != NULL)
            {
                top = top->right;
                while (top != NULL)
                {
                    inorder.push(top);
                    top = top->left;
                }
            }
            top = revInorderTop;
            revInorder.pop();
            count++;
            if (top->left != NULL)
            {
                top = top->left;
                while (top != NULL)
                {
                    revInorder.push(top);
                    top = top->right;
                }
            }
        }
        else if (inorderTop->data + revInorderTop->data > s)
        {
            BinaryTreeNode<int> *top = revInorderTop;
            revInorder.pop();
            count++;
            if (top->left != NULL)
            {
                top = top->left;
                while (top != NULL)
                {
                    revInorder.push(top);
                    top = top->right;
                }
            }
        }
        else
        {
            BinaryTreeNode<int> *top = inorderTop;
            inorder.pop();
            count++;
            if (top->right != NULL)
            {
                top = top->right;
                while (top != NULL)
                {
                    inorder.push(top);
                    top = top->left;
                }
            }
        }
    }
}
int main()
{
    BinaryTreeNode<int> *root = takeInput();
    int s;
    cin >> s;
    printNodesSumToS(root, s);
    delete root;
}
/*
Given a binary search tree and an integer S, find pair of nodes in the BST which sum to S. You can use extra space of the order of O(log n).
Note:
1. Assume BST contains all unique elements.
2. In a pair, print the smaller element first.
Input Format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.   
The following line of input contains an integer, that denotes the value of S.
Output format:
You have to print each pair in a different line (pair elements separated by space). The order of different pairs, to be printed, does not matter.
Constraints:
Time Limit: 1 second   

Sample Input 1:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
12
Sample Output 1:
2 10
5 7
*/
