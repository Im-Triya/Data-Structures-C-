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

void Insert(node* &head, int val)
{
    node* n=new node(val);
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
    return;
}

void Display(node* &head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ->\t";
        temp=temp->next;
    }
    cout<<endl;
}

void Insert_before(node* &head, int val, int ele)
{
    node* n=new node(val);
    if(head->data==ele)
    {
        n->next=head;
        head=n;
        return;
    }

    node* temp=head;
    while(temp->next->data!=ele)
    {
        temp=temp->next;
    }

    node* x=temp->next;
    temp->next=n;
    n->next=x;
}

void Insert_after(node* &head, int val, int ele)
{
    node* n=new node(val);
    
    node* temp=head;
    while(temp->data!=ele)
    {
        temp=temp->next;
    }

    node* x=temp->next;
    temp->next=n;
    n->next=x;
}

void Delete(node* &head, int ele)
{
    node* temp=head;
    while(temp->next->data!=ele)
    {
        temp=temp->next;
    }

    node* x=temp->next->next;
    node* todel=temp->next;
    temp->next=x;
    delete(todel);
}

void Reverse(node* &head)
{
    node* prev=NULL;
    node* curr=head;
    node* nxtptr=head->next;

    while(curr!=NULL)
    {
        nxtptr=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxtptr;
    }

    head=prev;
    return;
}

void Sort(node* &head)
{
    node* temp1=head;
    node* temp2=head;
    node*head2=NULL;
    int min;
    while(temp1!=NULL)
    {
        min=temp2->data;
        temp2=temp1->next;
        while(temp2!=NULL)
        {
            if(temp2->data < min)
            {
                min=temp2->data;
            }
            cout<<min;
            temp2=temp2->next;
        }
        Insert(head2, min);
        Display(head2);
        temp1=temp1->next;
    }
    head=head2;
}

void Alternate_Delete(node* &head)
{
    int x=1;
    node* temp=head;
    while(temp->next!=NULL)
    {
        if(x%2==0)
        {
            node* nxt=temp->next->next;
            Delete(head, temp->data);
            temp=nxt;
            continue;
        }
        
        x++;
        temp=temp->next;
    }
    return;
}

void Insert_sorted(node* &head, int ele)
{
    node* n=new node(ele);
    node*temp=head;

    while(!((temp->data < ele) && (temp->next->data > ele)))
    {
        temp=temp->next;
    }

    Insert_after(head, ele, temp->data);
}

int main()
{
    node* head=NULL;
    int n;
    for(int i=0;i<10;i++)
    {
        cout<<"Enter the elements of the list:";
        cin>>n;
        Insert(head, n);
    }

    cout<<"Inserting Before: "<<endl;
    Display(head);
    Insert_before(head,0,5);
    Display(head);
    
    cout<<"\n\nInserting After: "<<endl;
    Insert_after(head,0,5);
    Display(head);

    cout<<"\n\nDeleting: "<<endl;
    Delete(head, 0);
    Display(head);

    cout<<"\n\nReversing: "<<endl;
    Reverse(head);
    Display(head);

    // Sort(head);
    // Display(head);

    cout<<"\n\nAlternate deleting: "<<endl;
    Alternate_Delete(head);
    Display(head);

    
    cout<<"\n\nInserting in sorted: "<<endl;
    Insert_sorted(head, 5);
    Display(head);
}