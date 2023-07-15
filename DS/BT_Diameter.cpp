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

int Height(node* &root)
{
    if(root==NULL)
    return 0;

    int l_height=Height(root->left);
    int r_height=Height(root->right);

    return ((max(l_height,r_height))+1);
}

int Diameter(node* &root)
{
    if(root==NULL)
    return 0;

    int l_height=Height(root->left);
    int r_height=Height(root->right);
    int curr_dia=l_height+r_height+1;

    int l_dia=Diameter(root->left);
    int r_dia=Diameter(root->right);

    return ( max( max(l_dia, r_dia), curr_dia));
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

    cout<<"Diameter: "<<Diameter(root);
}