/*
      Given a MxN matrix, with some cells as blocked you have to -
      1) Find a path form src to dest
      2) Count the no. of paths from src  to dest
      3) Print all possible paths
      Given the rat can move only forward and down.

*/

#include <iostream>
using namespace std;

//using only recursion
/*
void f(int **a,int m,int n,int i,int j,char *out, int k)
{
         //check where to go
         //right
         if(j+1<n && i<m && a[i][j+1]!=1 )
         {
            out[k]='r';
            f(a,m,n,i,j+1,out,k+1);
         }
         //down
         if(i+1<m && j<n && a[i+1][j]!=1)
         {
            out[k]='d';
            f(a,m,n,i+1,j,out,k+1);
         }
        //base case
        if(i==m-1 && j==n-1)
         {
            out[k]='\0';
            cout<<out<<endl;
            return;
         }
         return;
}

int main()
{
   int m,n;
   cin>>m>>n;
   int **a=new int*[m];
   for(int i=0;i<m;i++)
   {
      a[i]=new int[n];
      for(int j=0;j<n;j++)
         a[i][j]=0;
   }

   for(int i=0;i<m;i++)
      for(int j=0;j<n;j++)
        cin>>a[i][j];

     for(int i=0;i<m;i++)
      {
         for(int j=0;j<n;j++)
        {
           cout<<a[i][j]<<" ";
        }
        cout<<endl;
      }

   char out[10000];
   f(a,m,n,0,0,out,0);
}

*/

//using recursion and backtracking
//printing solution matrix

bool f(int **a,int m,int n,int **sol,int i,int j)
{
   //base case
      if(i==m&&j==n)
      {
         sol[i][j]=1;
         for(int i=0;i<=m;i++)
         {
            for(int j=0;j<=n;j++)
               cout<<sol[i][j]<<" ";
            cout<<endl;
         }
         cout<<endl;
         return true;
      }

      //rat should be inside the grid
      if(i>m || j>n)
            return false;

      if(a[i][j]==1)
            return false;

      //assume solution exists through current cell
      sol[i][j]=1;
      bool rightSuccess=f(a,m,n,sol,i,j+1);
      bool downSuccess=f(a,m,n,sol,i+1,j);

      //backtracking
      sol[i][j]=0;
      //initially solution matrix 0
      //finally solution matrix 0

      if(rightSuccess||downSuccess)
         return true;
      return false;

}



int main()
{
   int m,n;
   cin>>m>>n;
   int **a=new int*[m];
   for(int i=0;i<m;i++)
   {
      a[i]=new int[n];
      for(int j=0;j<n;j++)
         a[i][j]=0;
   }

   for(int i=0;i<m;i++)
      for(int j=0;j<n;j++)
        cin>>a[i][j];

     for(int i=0;i<m;i++)
      {
         for(int j=0;j<n;j++)
           cout<<a[i][j]<<" ";
        cout<<endl;
      }

      cout<<endl;

      cout<<"Solutions"<<endl;

      int **sol=new int*[m];
      for(int i=0;i<m;i++)
      {
          sol[i]=new int[n];
         for(int j=0;j<n;j++)
            sol[i][j]=0;
      }

   bool maze =f(a,m-1,n-1,sol,0,0);
   if(maze==false)
      cout<<"Maze not solvable";

}




























