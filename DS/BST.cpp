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

void inorder(node* &root)
{
    if(root==NULL)
    return;

    inorder(root->left);
    cout<<root->data<<"\t";
    inorder(root->right);
}

node* Insert_BST(node* & root, int ele)
{
    if(root==NULL)
    {
        node* n=new node(ele);
        return n;
    }

    if(root->data<ele)
    {
        root->right=Insert_BST(root->right, ele);
    }

    else if(root->data>ele)
    {
        root->left=Insert_BST(root->left, ele);
    }

    return root;
}

node* Search_BST(node* &root, int key)
{
    if(root==NULL)
    return NULL;

    if(root->data==key)
    return root;

    else if(root->data>key)
    return Search_BST(root->left, key);

    else
    return Search_BST(root->right,key);

}

node* Succ(node* &root)
{
    node* curr=root;
    while(curr && curr->left!=NULL)
    curr=curr->left;

    return curr;
}

node* Delete_BST(node* &root, int key)
{
    if(key<root->data)
    root->left=Delete_BST(root->left, key);

    else if(key>root->data)
    root->right=Delete_BST(root->right, key);

    else
    {
        if(root->left==NULL)
        {
            node* temp=root->right;
            free(root);
            return temp;
        }

        if(root->right==NULL)
        {
            node* temp=root->left;
            free(root);
            return temp;
        }

        node* temp=Succ(root->right);
        root->data=temp->data;
        root->right=Delete_BST(root->right, temp->data);
    }
    return root;
}
int main()
{
    node* root=NULL;
    int a[]={5,1,3,4,2,7};
    for(int i=0;i<6;i++)
    {
        root=Insert_BST(root,a[i]);
    }

    cout<<"Inorder: "<<endl;
    inorder(root);

    cout<<"\nSearch: ";
    node* n=Search_BST(root, 3);
    cout<<n->data<<endl;

    root=Delete_BST(root, 3);
    inorder(root);
}