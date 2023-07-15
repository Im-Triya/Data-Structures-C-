#include<iostream>
using namespace std;
class node
{
    public: 
    int data;
    node* next;
    node* prev;

    node(int i)
    {
        data=i;
        next=NULL;
        prev=NULL;
    }
};

void InsertAtHead(node* &head, int val)
{
    node* n=new node(val);
    n->next=head;
    if(head!=NULL)
    head->prev=n;

    head=n;
}

void InsertAtTail(node* &head, int val)
{
    if(head==NULL)
    {
        InsertAtHead(head, val);
        return;
    }
    node* n=new node(val);
    node* temp=head;

    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
}



void Display(node* head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->\t";
        temp=temp->next;
    }
    cout<<endl;
}
int length(node* head)
{
    node* temp=head;
    int l=0;
    while(temp!=NULL)
    {
        l++;
        temp=temp->next;
    }
}

void Intersect(node* &head1, node* &head2, int pos)
{
    node* temp1=head1;
    pos--;
    while(pos--)
    {
        temp1=temp1->next;
    }
    node* temp2=head2;
    while(temp2->next!=NULL)
    {
        temp2=temp2->next;
    }
    temp2->next=temp1;
}
int Intersection(node* &head1, node* &head2)
{
    int l1=length(head1);
    int l2=length(head2);

    int d=0;
    node *ptr1;
    node *ptr2;

    if(l1>l2)
    {
        d=l1=l2;
        ptr1=head1;
        ptr2=head2;
    }
    else
    {
        d=l2-l1;
        ptr2=head1;
        ptr1=head2;
    }

    while(d)
    {
        ptr1=ptr1->next;
        if(ptr1==NULL)
        return -1;

        d--;
    }

    while(ptr1!=NULL && ptr2!=NULL)
    {
        if(ptr1==ptr2)
        return ptr1->data;

        ptr1=ptr1->next;
        ptr2-ptr2->next;
    }
    return -1;
}

int main()
{
    node* head1=NULL;
    node* head2=NULL;
    InsertAtTail(head1,1);
    InsertAtTail(head1,2);
    InsertAtTail(head1,3);
    InsertAtTail(head1,4);
    InsertAtTail(head1,5);
    InsertAtTail(head1,6);
    InsertAtTail(head2,9);
    InsertAtTail(head2,10);
    Intersect(head1,head2,3);

    Display(head1);
    Display(head2);

    cout<<"\n\n"<<Intersection(head1, head2)<<endl;
}