/*Wave Print of a 2D Array*/
#include <iostream>
using namespace std;

void print_2d(int **a,int r,int c)
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
void wave_print(int **a,int r,int c)
{
    int ci=0,ri=0;
    while(ci<c)
    {
        if(ci%2==0)
        {
            while(ri<r)
            {
                cout<<a[ri++][ci]<<" ";
            }
        }
        else
        {
            while(ri>=0)
            {
                cout<<a[ri--][ci]<<" ";
            }
        }

        ci++;
    }
}

int main()
{
    int m,n;
    cout<<"Enter limits";
    cin>>m>>n;

    /*Now if we declare 2D array the normal way,
      we cannot pass it into our function because in our function we have used pointers.*/

    int **a;
    *a=new int[m];

    for(int i = 0; i < m; i ++)
    {
        a[i] = new int[n];
    }

    /*Now we have initialized a pointer to a 2D Array. */

 a[0][0]=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            a[i][j]=a[i][j]+1;
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

    print_2d(a,m,n);
    wave_print(a,m,n);
}
