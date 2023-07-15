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

void preorder(node* &root)
{
    if(root==NULL)
    return;

    cout<<root->data<<"\t";
    preorder(root->left);
    preorder(root->right);
}

void inorder(node* &root)
{
    if(root==NULL)
    return;

    inorder(root->left);
    cout<<root->data<<"\t";
    inorder(root->right);
}

void postorder(node* &root)
{
    if(root==NULL)
    return;

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<"\t";
}

int Search(int inorder[], int start, int end, int curr)
{
    for(int i=start;i<=end;i++)
    {
        if(inorder[i]==curr)
        return i;
    }
    return -1;
}

node* Build_Tree_preorder(int preorder[], int inorder[], int start, int end)
{
    if(start>end)
    return NULL;

    static int idx=0;
    int curr=preorder[idx];
    idx++;

    node* n=new node(curr);
    if(start==end)
    return n;

    int pos=Search(inorder, start, end, curr);
    n->left=Build_Tree_preorder(preorder, inorder, start, (pos-1));
    n->right=Build_Tree_preorder(preorder, inorder, (pos+1), end);

    return n;

}

node* Build_Tree_postorder(int postorder[], int inorder[], int start, int end)
{
    if(start>end)
    return NULL;

    static int idx=end;
    int curr=postorder[idx];
    idx--;

    node* n=new node(curr);
    if(start==end)
    return n;

    int pos=Search(inorder, start, end, curr);
    n->right=Build_Tree_postorder(postorder, inorder, (pos+1), end);
    n->left=Build_Tree_postorder(postorder, inorder, start, (pos-1));

    return n;
}

int main()
{
    int inorder_arr[]={4,2,5,1,6,3,7};
    int preorder_arr[]={1,2,4,5,3,6,7};
    int postorder_arr[]={4,5,2,6,7,3,1};
    cout<<"\nPreorder: \n";
    node* root2=Build_Tree_preorder(preorder_arr, inorder_arr,0,6);
    preorder(root2);

    cout<<"\nPostorder: \n";
    node* root3=Build_Tree_postorder(postorder_arr, inorder_arr,0,6);
    postorder(root3);
}