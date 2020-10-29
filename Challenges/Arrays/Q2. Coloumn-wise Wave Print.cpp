//Column-wise wave print

#include <iostream>
using namespace std;

void column_wise_wave_print(int **a,int m,int n)
{
    int i=0,j=0;
    cout<<endl;

    for(int j=0;j<n;j++)
    {
        if(j%2==0)
            for(int i=0;i<m;i++)
            cout<<a[i][j]<<" ";
        else
            for(int i=m-1;i>=0;i--)
            cout<<a[i][j]<<" ";

    }

}

int main()
{
    int m,n;
    cin>>m>>n;

    int **a=new int*[m];
    for(int i=0;i<m;i++)
    {
        a[i]=new int[n];
    }

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    column_wise_wave_print(a,m,n);

}
