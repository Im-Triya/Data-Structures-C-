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
        prev=next=NULL;
    }
};

void Insert(node* &head, int x)
{
    node* n=new node(x);
    if(head==NULL)
    {
        head=n;
        n->next=head;
        head->prev=n;
        return;
    }

    node* temp=head;
    while(temp->next!=head)
    temp=temp->next;

    temp->next=n;
    n->prev=temp;
    n->next=head;
    head->prev=n;
}

void Delete(node* &head, int ele)
{
    node* todel;
    if(head->data==ele)
    {
        todel=head;
        head->prev->next=head->next;
        head->next->prev=head->prev;
        head=head->next;
        delete(todel);
        return;
    }

    node* temp=head;
    while(temp->data!=ele)
    temp=temp->next;

    todel=temp;
    temp->next->prev=temp->prev;
    temp->prev->next=temp->next;
    delete(todel);
    return;
}

void Display(node* &head)
{
    cout<<head->data<<"\t";
    node* temp=head->next;
    while(temp!=head)
    {
        cout<<temp->data<<"\t";
        temp=temp->next;
    }
    cout<<endl;
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