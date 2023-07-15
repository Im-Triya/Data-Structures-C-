#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;
    node* prev;

    node(int val)
    {
        data=val;
        next=NULL;
        prev=NULL;
    }
};

void Insert(node* &head, int x)
{
    node* n=new node(x);
    if(head==NULL)
    {
        head=n;
        // head->next=n;
        // n->prev=head;
        return;
    }

    node* temp=head;
    while(temp->next!=NULL)
    temp=temp->next;

    temp->next=n;
    n->prev=temp;
}

void Display(node* &head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"\t";
        temp=temp->next;
    }
    cout<<endl;
}

void Delete(node* &head, int ele)
{
    node* todel;
    if(head->data==ele)
    {
        todel=head;
        head=head->next;
        head->next->prev=NULL;
        delete(todel);
        return;
    }

    node* temp=head;
    while(temp->data!=ele)
    temp=temp->next;
    todel=temp;

    if(temp->next==NULL)
    {
        temp->prev->next=NULL;
        delete(todel);
        return;
    }

    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    delete(todel);
}
int main()
{
    node* head=NULL;
    Insert(head,1);
    Insert(head,2);
    Insert(head,3);
    Insert(head,4);
    Insert(head,5);
    Display(head);
    Delete(head, 5);
    Display(head);
}