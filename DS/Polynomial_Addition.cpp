#include<iostream>
using namespace std;

class node
{
    public:
    int coef;
    int pow;
    node* next;
    node* prev;

    node(int c, int p)
    {
        coef=c;
        pow=p;
        next=NULL;
        prev=NULL;
    }
};

void Insert(node* &head, int c, int p)
{
    node* n=new node(c,p);
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
        cout<<temp->coef<<"x^"<<temp->pow<<"+\t";
        temp=temp->next;
    }
    cout<<endl;
}

void Add(node* &head1, node* &head2)
{
    node* head3=NULL;
    node* temp1=head1;
    node* temp2=head2;
    int sum;
    while( (temp1!=NULL) || (temp1!=NULL))
    {
        if(temp1->pow==temp2->pow)
        {
            sum=temp1->coef+temp2->coef;
            Insert(head3, sum, temp1->pow);
            temp1=temp1->next;
            temp2=temp2->next;
        }

        else if((temp1->pow)>(temp2->pow))
        {
            Insert(head3, temp1->coef, temp1->pow);
            temp1=temp1->next;
            temp2=temp2;
        }
        else
        {
            Insert(head3, temp2->coef, temp2->pow);
            temp2=temp2->next;
            temp1=temp1;
        }

        if(temp2==NULL)
        {
           while(temp1!=NULL)
           {
                Insert(head3, temp1->coef, temp1->pow);
                temp1=temp1->next;
           }
        }

        if(temp1==NULL)
        {
            while(temp2!=NULL)
            {
                Insert(head3, temp2->coef, temp2->pow);
                temp2=temp2->next;
            }
        }
        
    }
    
    Display(head3);
}

int main()
{
    node* head1=NULL;
    Insert(head1, 4,4);
    Insert(head1, 3,3);
    Insert(head1, 2,2);
    Insert(head1, 1,1);
    Display(head1);
    node* head2=NULL;
    Insert(head2, 5,9);
    Insert(head2, 4,8);
    Insert(head2, 3,7);
    Insert(head2, 2,2);
    Display(head2);

    Add(head1, head2);
}