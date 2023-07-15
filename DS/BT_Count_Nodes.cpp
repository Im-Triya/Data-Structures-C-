#include<iostream>
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

int count_Nodes(node* &root)
{
    if(root==NULL)
    return 0;

    return ((count_Nodes(root->left)) +(count_Nodes(root->right)) +1);
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

    cout<<"No of nodes: "<<count_Nodes(root);
}