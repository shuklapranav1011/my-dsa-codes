//NxN subgrid
//divided into 9 subgrids
//every row has number from 1 to 9
//every coloumn has number form 1 to 9
//every subgrid has number from 1 to 9
//no number in a subgrid, row or coloumn is repeated


#include <iostream>
#include <cmath>
using namespace std;

bool safe_Place(int sol[][9],int i,int j,int n,int k)
{
      //checking row
      for(int row=0;row<n;row++)
         if(sol[row][j]==k)
            return false;

      //checking coloumn
      for(int coloumn=0;coloumn<n;coloumn++)
         if(sol[i][coloumn]==k)
         return false;

      //checking grid
      int x,y;

      int a=sqrt(n);
      x=(i/a)*a;
      y=(j/a)*a;

      for(int t=x;t<x+a;t++)
         for(int l=y;l<y+a;y++)
            if(sol[t][l]==k)
               return false;

      //now all conditions satisfied
      return true;
}

bool solver(int sol[][9],int i,int j,int n)
{
   //whole grid solved
   if(i==n)
   {
      //print the solved grid
      for(int i=0;i<n;i++)
         for(int j=0;j<n;j++)
            cout<<" "<<sol[i][j]<<" ";
      cout<<endl;
   }

   if(j==n)
      return solver(sol,i+1,0,n);

   if(sol[i][j]!=0)
      return solver(sol,i,j+1,n);

   //recursive case
   //fill the current cell with possible options
   for(int k=1;k<=9;k++)
      {
            if(safe_Place(sol,i,j,n,k))
            {
               //assuming true
               sol[i][j]=k;

               bool couldwesolve = solver(sol,i,j+1,n);
               if(couldwesolve)
                  return true;
            }
      }
      //program gets here means no value of k from 1 to 9 satisfied
      //backtracking
      sol[i][j]=0;
      return false;
}

int main()
{

   int sol[9][9]={
      {5,3,0,0,7,0,0,0,0},
      {6,0,0,1,9,6,0,0,0},
      {0,9,8,0,0,0,0,6,0},
       {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
         {7,0,0,0,2,0,0,0,6},
          {0,6,0,0,0,0,2,8,9},
           {0,0,0,4,1,9,0,0,5},
            {0,0,0,0,8,0,0,7,9}};


   for(int i=0;i<9;i++)
   {
      for(int j=0;j<9;j++)
         cout<<" "<<sol[i][j]<<" ";
         cout<<endl;
   }

   cout<<endl;
   bool next=solver(sol,0,0,9);

}


