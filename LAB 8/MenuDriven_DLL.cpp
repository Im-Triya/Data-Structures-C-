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

void Insert_Rear(node* &head, int ele)
{
    node* n=new node(ele);
    if(head==NULL)
    {
        head=n;
        return;
    }

    node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }

    temp->next=n;
    n->prev=temp;
}

void Delete_Rear(node* &head)
{
    node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->prev->next=NULL;
    
    delete(temp);
}

void Insert_At(node* &head, int pos, int ele)
{
    node* n=new node(ele);
    node* temp=head;
    int i=1;
    while(i!=pos)
    {
        temp=temp->next;
        i++;
    }
    n->next=temp->next;
    n->prev=temp;
    temp->next=n;
}

void Delete_At(node* &head, int pos)
{
    node* temp=head;
    int i=1;
    while(i!=pos)
    {
        temp=temp->next;
        i++;
    }
    node* todel=temp;
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    delete(todel);
}

void Insert_After(node* &head, int ele, int val)
{
    node* n=new node(val);
    node* temp=head;

    while(temp->data!=ele)
    {
        temp=temp->next;
    }

    if(temp->next==NULL)
    {
        temp->next=n;
        n->prev=temp;
        return;
    }
    n->next=temp->next;
    temp->next->prev=n;
    n->prev=temp;
    temp->next=n;
}

void Insert_Before(node* &head, int ele, int val)
{
    node* n=new node(val);
    node* temp=head;
    if( head->data== ele)
    {
        cout<<"here"<<endl;
        n->next=head;
        head->prev=n;
        head=n;
        return;
    }

    while(temp->next->data!=ele)
    {
        temp=temp->next;
    }
    cout<<"here"<<endl;
    n->next=temp->next;
    temp->next->prev=n;
    n->prev=temp;
    temp->next=n;
}

node* Reverse(node* &head)
{
    node* temp=head;
    node* head2=NULL;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    node* temp2=temp;
    while(temp2->prev!=NULL)
    {
        Insert_Rear(head2,temp2->data);
    }
    return head2;
}

void Display(node* &head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"<->\t";
        temp=temp->next;
    }
    cout<<endl<<endl;
}
int main()
{
    node* head=NULL;
    int n;
    for(int i=1;i<=10;i++)
    {
        cout<<"Enter element:  ";
        cin>>n;
        Insert_Rear(head,n);
    }

    Display(head);
    Delete_Rear(head);
    Display(head);

    Insert_At(head, 3, 0);
    Display(head);

    Delete_At(head, 4);
    Display(head);

    Insert_After(head, 9, 10);
    Display(head);

    Insert_Before(head, 1, 0);
    Display(head);

    head=Reverse(head);
    Display(head);
}