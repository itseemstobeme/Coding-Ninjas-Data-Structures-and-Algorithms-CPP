#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

template <typename T>
class TreeNode {
   public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};


TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

#define Pair pair<TreeNode<int>*,TreeNode<int>*> 
TreeNode<int>* maximum(TreeNode<int>* x,TreeNode<int>* y)   //Returns pointer of node with maximum data
{   if(x==NULL && y==NULL)
    return NULL;
    if(x==NULL && y!=NULL)
    return y;
    if(x!=NULL && y==NULL)
    return x;

    return (x->data > y->data)?x:y;
}
Pair* secondmax(TreeNode<int>* root)
{
    if(root==NULL)
    return NULL;

    Pair* ans=new Pair(root,NULL);
    
    for(int i=0;i<root->children.size();++i)
    {
        Pair* temp=secondmax(root->children[i]);
        if(temp!=NULL)
        {
            if(temp->first->data > ans->first->data)    
            {   
                ans->second=maximum(ans->first,maximum(ans->second,temp->second));
                ans->first=temp->first;
            }
            else
            if(temp->first->data < ans->first->data)
            ans->second=maximum(temp->first,maximum(ans->second,temp->second));
            else
            ans->second=maximum(ans->second,temp->second);       //If both max of ans and temp is same,
                                                                //SMax can only be out of second of both ans & temp
        }
    }
    
    return ans;
}
TreeNode<int>* getSecondLargestNode(TreeNode<int>* root)
{
    if(root==NULL)
    return NULL;

    Pair* ans=secondmax(root);
    return ans->second;
}
int main() {
    TreeNode<int>* root = takeInputLevelWise();

    TreeNode<int>* ans = getSecondLargestNode(root);

    if (ans != NULL) {
        cout << ans->data;
    } else {
        cout << INT_MIN;
    }

}

/*
Given a generic tree, find and return the node with second largest value in given tree.
Note: Return NULL if no node with required value is present.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.
Output Format :
The first and only line of output contains data of the node with second largest data.
Constraints:
Time Limit: 1 sec

Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1 :
40
*/