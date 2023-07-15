#include<iostream>
using namespace std;

class SMT
{
    public:
    int row, col, val;

    void create_SMT(int r, int c, int v)
    {
        row=r;
        col=c;
        val=v;
    }
};

void Dispaly(SMT S[], int c)
{
    for(int i=0;i<=c;i++)
    {
        cout<<S[i].row<<"\t"<<S[i].col<<"\t"<<S[i].val<<endl;
    }
}
int main()
{
    int n,m,c=0;
    SMT S[10];
    cout<<"Enter number of rows and columns: ";
    cin>>n>>m;
    int a[n][m]={0};
    cout<<"Enter the elements of the matrix: ";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
            if(a[i][j]!=0)
            {
                c++;
                S[c].create_SMT(i,j,a[i][j]);
            }
        }
    }
    S[0].create_SMT(n,m,c);

    Dispaly(S,c);
}