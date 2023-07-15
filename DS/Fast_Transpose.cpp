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

void Fast_Transpose(SMT S[], SMT T[])
{
    T[0].row=S[0].col;
    T[0].col=S[0].row;
    T[0].val=S[0].val;
    int RT[S[0].col]={0};
    int SL[S[0].col]={0};

    for(int i=1;i<=S[0].val;i++)
    {
        RT[S[i].col]++;
    }

    SL[0]=1;
    for(int i=1;i<S[0].col;i++)
    {
        SL[i]=SL[i-1]+RT[i-1];
    }

    for(int i=1;i<=S[0].val;i++)
    {
        int j=SL[S[i].col]++;
        T[j].row=S[i].col;
        T[j].col=S[i].row;
        T[j].val=S[i].val;
    }

    Dispaly(T, S[0].val);
}
int main()
{
    int n,m,c=0;
    SMT S[10];
    SMT T[10];
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
    cout<<"\nFast Transpose: "<<endl;
    Fast_Transpose(S,T);
}