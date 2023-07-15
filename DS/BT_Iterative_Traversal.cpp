#include<iostream>
#include<stack>
using namespace std;

class node
{
    public:
    int data;
    node* left;
    node* right;

    node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};

void preorder(node* &root)
{
    stack<node*> s;
    s.push(root);

    while(!s.empty())
    {
        node* curr=s.top();
        cout<<curr->data<<"\t";
        s.pop();

        if(curr->right!=NULL)
        {
            s.push(curr->right);
        }

        if(curr->left!=NULL)
        {
            s.push(curr->left);
        }
    }
}

void inorder(node* &root)
{
    stack<node*> s;
    node* curr=root;
    bool flag=true;

    while(flag==true)
    {
        while(curr!=NULL)
        {
            s.push(curr);
            curr=curr->left;
        }

        curr=s.top();
        cout<<curr->data<<"\t";
        s.pop();

        if(s.empty() && curr->right==NULL)
        flag=false;

        curr=curr->right;
    }
}

void postorder(node* &root)
{
    stack<node*> s1;
    stack<node*> s2;
    s1.push(root);
    while(!s1.empty())
    {
        node* curr=s1.top();
        s2.push(curr);
        s1.pop();

        if(curr->left!=NULL)
        s1.push(curr->left);

        if(curr->right!=NULL)
        s1.push(curr->right);
    }

    while(!s2.empty())
    {
        node* curr=s2.top();
        cout<<curr->data<<"\t";
        s2.pop();
    }
}

int main()
{
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->right->left=new node(6);
    root->left->right=new node(5);
    root->right->right=new node(7);

    cout<<"\nPreorder: ";
    preorder(root);
    cout<<"\nInorder: ";
    inorder(root);
    cout<<"\nPostorder: ";
    postorder(root);
}