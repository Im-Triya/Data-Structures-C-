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

node* LCA(node* &root, int n1, int n2)
{
    if(root==NULL)
    return NULL;

    if(root->data==n1 || root->data==n2)
    return root;

    node* left_LCA=LCA(root->left, n1,n2);
    node* right_LCA=LCA(root->right,n1,n2);

    if(left_LCA && right_LCA)
    return root;

    else if(left_LCA!=NULL)
    return left_LCA;

    else
    return right_LCA;
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

    node* lca=LCA(root, 4,6);
    cout<<lca->data;
}