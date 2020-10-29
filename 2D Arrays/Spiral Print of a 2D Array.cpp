//Spiral Print

#include <iostream>
using namespace std;
int main()
{//Spiral Print
    int m,n;
    cout<<"Enter Row and Coloumn";
    cin>>m>>n;

    int a[m][n];
    int k=0;
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

    int beg_row=0,last_row=m-1;
    int beg_col=0,last_col=n-1;

    int i,j;
    int t=m*n;
    int l=0;

    while(beg_row<=last_row && beg_col<=last_col)
    {   if(l!=t) //to prevent repeated printing of rows and coloumns
        {
        for(i=beg_col;i<=last_col;i++)
        {
            cout<<a[beg_row][i]<<" "; l++;
        }
        beg_row++;
        }

        if(l!=t) //to prevent repeated printing of rows and coloumns
        {
        for(i=beg_row;i<=last_row;i++)
        {
            cout<<a[i][last_col]<<" ";l++;
        }
        last_col--;
        }

        if(l!=t) //to prevent repeated printing of rows and coloumns
        {
        for(i=last_col; i>=beg_col;i--)
        {
            cout<<a[last_row][i]<<" ";l++;
        }
        last_row--;
        }

        if(l!=t) //to prevent repeated printing of rows and coloumns
        {
        for(i=last_row;i>= beg_row;i--)
        {
            cout<<a[i][beg_col]<<" "; l++;
        }
        beg_col++;
        }
    }
}
