#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node* next;

    node(int val)
    {
        data=val;
        next=NULL;
    }
};

void Insert(node* &head, int x)
{
    node* n=new node(x);
    if(head==NULL)
    {
        head=n;
        return;
    }

    node* temp=head;
    while(temp->next!=NULL)
    temp=temp->next;

    temp->next=n;
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
        head=head->next;;
        delete(todel);
        return;
    }

    node* temp=head->next;
    node* temp2=head;
    while(temp->data!=ele)
    {
        temp2=temp2->next;
        temp=temp->next;
    }

    if(temp->next==NULL)
    {
        todel=temp;
        temp2->next=NULL;
        delete(todel);
        return;
    }

    todel=temp;
    temp2->next=temp->next;
    delete(todel);
    return;


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