#include<iostream>
using namespace std;
#define max_size 100
class SMT
{
    public:
    int row,col,value;
public:
    void createSMT(int r, int c, int val)
    {
        row=r;
        col=c;
        value=val;
    }

    void Display(SMT S[], int n, int m)
    {
        int index=0;
        cout<<S[index].row<<"\t"<<S[index].col<<"\t"<<S[index].value<<"\t";
        index++;
        for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(S[index].row==i && S[index].col==j)
            {
                cout<<S[index].row<<"\t"<<S[index].col<<"\t"<<S[index].value<<"\t";
                index++;
            }
            cout<<endl;
        }
    }
    }

    void FastTranspose(SMT S[], SMT T[])
    {
        int col=S[0].col, NT=S[0].value,i,j;
        T[0].col=S[0].row;
        T[0].row=S[0].col;
        T[0].value=S[0].value;

        int RT[col]={0};
        int SL[col]={0};

        for(i=1;i<=NT;i++)
        {
            RT[S[i].col]++;
        }

        SL[0]=1;
        for(i=1;i<col;i++)
        {
            SL[i]=SL[i-1]+RT[i-1];
        }

        for(i=1;i<=NT;i++)
        {
            j=SL[S[i].col]++;
            T[j].col=S[i].row;
            T[j].row=S[i].col;
            T[j].value=S[i].value;
        }
    }
};
main()
{
    SMT S[max_size];
    SMT T[max_size];
    int m,n,i,j,c=0;
    cout<<"Enter number of rows: ";
    cin>>n;
    cout<<"Enter number of columns: ";
    cin>>m;
    int a[n][m];
    cout<<"Enter the elements of the sparse matrix: "<<endl;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin>>a[i][j];
            if(a[i][j]!=0)
            {
                S[i+1].createSMT(i,j,a[i][j]);
                c++;
            }
        }
    }
    S[0].createSMT(n,m,c);
    cout<<"Printing the original Sparse Matrix:"<<endl;
    S[0].Display(S,n,m);
    cout<<"Printing the transpose of the original Sparse Matrix:"<<endl;
    S[0].FastTranspose(S,T);
    T[0].Display(T,n,m);
}
