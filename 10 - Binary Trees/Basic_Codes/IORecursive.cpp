#include <iostream>
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
        left = right = NULL;
    }
    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};

BinaryTreeNode<int> *input();
void print(BinaryTreeNode<int> *root);
int main()
{
    cout << "Enter root data : ";
    BinaryTreeNode<int> *root = input();
    print(root);
}

BinaryTreeNode<int> *input()
{
    int data;
    cin >> data;
    BinaryTreeNode<int> *root;
    if (data != -1)
        root = new BinaryTreeNode<int>(data);
    else
        return NULL;

    cout << "Enter left child of " << data << " : ";
    root->left = input();
    cout << "Enter right child of " << data << " : ";
    root->right = input();

    return root;
}
void print(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;

    cout << root->data << " : ";
    if (root->left != NULL)
        cout << root->left->data;
    if (root->right != NULL)
        cout << "," << root->right->data;

    cout << endl;
    print(root->left);
    print(root->right);
}