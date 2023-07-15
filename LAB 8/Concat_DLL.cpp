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
        next=prev=NULL;
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

node* Concat(node* &head1, node* &head2)
{
    node* temp=head1;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }

    temp->next=head2;
    return head1;
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
    node* head1=NULL;
    node* head2=NULL;
    int n;

    for(int i=1;i<=10;i++)
    {
        cout<<"Enter element of list 1:  ";
        cin>>n;
        Insert_Rear(head1,i);
    }

    for(int i=1;i<=10;i++)
    {
        cout<<"Enter element of list 2:  ";
        cin>>n;
        Insert_Rear(head2,i);
    }
    node* head3=Concat(head1, head2);
    Display(head3);
}