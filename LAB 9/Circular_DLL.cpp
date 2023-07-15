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

void Insert(node* &head, int val)
{
    node* n=new node(val);
    if(head==NULL)
    {
        head=n;
        n->next=head;
        head->prev=n;
        return;
    }

    node* temp=head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }

    temp->next=n;
    n->prev=temp;
    n->next=head;
    head->prev=n;
    return;
}

void Delete(node* &head, int ele)
{
    node* temp=head;

    if(ele==head->data)
    {
        node* todel=head;
        head->prev->next=head->next;
        head->next->prev=head->prev;
        head=head->next;
        delete(todel);
        return;
    }

    while(temp->data!=ele)
    {
        temp=temp->next;
    }
    node* todel=temp;
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    delete(todel);
}

void Display(node* &head)
{
    node* temp=head;
    cout<<temp->data<<"<->\t";
    temp=temp->next;
    while(temp!=head)
    {
        cout<<temp->data<<"<->\t";
        temp=temp->next;
    }

    cout<<endl;
}

int main()
{
    node* head=NULL;
    int n;
    for(int i=1;i<=10;i++)
    {
        // cout<<"Enter element:  ";
        // cin>>n;
        Insert(head,i);
    }

    Display(head);

    Delete(head, 1);
    Display(head);
}
