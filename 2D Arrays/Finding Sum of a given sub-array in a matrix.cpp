#include <iostream>
using namespace std;

void extract_prefix_sum_matrix(int **a,int m,int n)
{
    int s=0;
    for(int i=0;i<m;i++)
    {   s=0;
        for(int j=0;j<n;j++)
        {
            s=s+a[i][j];
            a[i][j]=s;
        }
    }

    for(int j=0;j<n;j++)
    {   s=0;
        for(int i=0;i<m;i++)
        {
            s=s+a[i][j];
            a[i][j]=s;
        }
    }

    cout<<"Prefix Sum Matrix is ="<<endl;

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void extract_particular_subarray_sum(int **a,int m,int n)
{
   int tli,tlj,bri,brj;

   cout<<"Enter top-left index";
   cin>>tli>>tlj;

   tli-=1;
   tlj-=1;

   cout<<"Enter bottom-right index";
   cin>>bri>>brj;

   bri-=1;
   brj-=1;

   extract_prefix_sum_matrix(a,m,n);

   cout<<"Sum of given subarray is = "<<endl;

   if(tli==0&&tlj==0)
   {
       cout<<a[bri][brj];
   }
   else if(tli!=0&&tlj==0)
   {
       cout<<(a[bri][brj]-a[tli-1][brj]);
   }
   else if(tli==0&&tlj!=0)
   {
       cout<<(a[bri][brj]-a[bri][tlj-1]);
   }
   else
   {
       cout<<(a[bri][brj]-a[bri][tlj-1]-a[tli-1][brj]+a[tli-1][tlj-1]);
   }
}


int main()
{
    int m;int n;
    cout<<"Enter Limits";
    cin>>m>>n;

    int **a;
    a=new int*[m];

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            a[i]=new int[n];
        }
    }

    cout<<"Enter Matrix";

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

    extract_particular_subarray_sum(a,m,n);
}
