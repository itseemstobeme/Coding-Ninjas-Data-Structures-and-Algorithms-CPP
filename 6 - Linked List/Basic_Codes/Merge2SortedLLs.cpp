#include <iostream>
using namespace std;
class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
Node* mergeTwoSortedLinkedLists(Node* h1, Node* h2)
{
    if(h1==NULL || h2==NULL)
    {
        if(h1==NULL && h2!=NULL)
        return h2;
        else
        if(h1!=NULL && h2==NULL)
        return h1;
        else
        return NULL;
    }
    Node* tail=NULL,*head=NULL;
    if(h1->data < h2->data)
    {
        head=h1;
        tail=h1;
        h1=h1->next;
    }
    else
    {
        head=h2;
        tail=h2;
        h2=h2->next;
    }

    while(h1!=NULL && h2!=NULL)
    {
        if(h1->data > h2->data)
        {
            tail->next=h2;
            tail=tail->next;
            h2=h2->next;
        }
        else
        {
            tail->next=h1;
            tail=tail->next;
            h1=h1->next;
        }
    }
    if(h1!=NULL)
    tail->next=h1;
    else
    if(h2!=NULL)
    tail->next=h2;

    return head;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head1 = takeinput();
		Node *head2 = takeinput();
		Node *head3 = mergeTwoSortedLinkedLists(head1, head2);
		print(head3);
	}
	return 0;
}
/*
Merge 2 sorted LLs and return head of new LL
Try solving it in O(1) auxillary space
*/