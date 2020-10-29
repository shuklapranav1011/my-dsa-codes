//Place N queens in an NxN keyboard such that all queens are safe

//single solution
#include <iostream>
using namespace std;
//is it safe to place a queen at the board at place (i,j)
bool is_Safe(int **sol,int i,int j,int n)
{
   //check for row
   for(int row=0;row<i;row++)
      if(sol[row][j]==1)
      return false;

   //for left diagonal
   int x=i;
   int y=j;
   while(x>=0 & y>=0)
   {
      if(sol[x][y]==1)
      return false;
      x--; y--;
   }

   //for right diagonal
    x=i;
    y=j;
    while(x>=0 & y<n)
   {
      if(sol[x][y]==1)
      return false;
      x--; y++;
   }

   //now all conditions checked
   return true;
}

bool place_queens(int **sol, int i,int n)
{
   //base case
   if(i==n)
   {
      //print current configuration
      for(int k=0;k<n;k++)
      {
         for(int l=0;l<n;l++)
            if(sol[k][l]==1)
               cout<<" Q ";
            else
               cout<<" _ ";
         cout<<endl;
      }
      return true;
   }

   //recursive case
   //try to place the queen in the current row and call on the remaining part
   //which is solver by recursion
   for(int j=0;j<n;j++)
   {
      if(is_Safe(sol,i,j,n))
           {
              sol[i][j]=1;

              bool nextqueenplaced=place_queens(sol,i+1,n);

              if(nextqueenplaced)
                 return true;
           }
      //it comes out of this means (i,j) is wrong
     //agar nai rkh paye to for loop aage chalega aur next loop pe try krega
     //but hme abi wali position se queen hatani bhi h

     //backtracking
      sol[i][j]=0;
   }
   //ab hm ek row me khn bhi nai rkh paa rhe h
   //we have tried for all positions in the current row but could not place
   return false;
}


int main()
{
      int n;
      cin>>n;
      int **sol=new int*[n];
      for(int i=0;i<n;i++)
        {
           sol[i]=new int[n];
           for(int j=0;j<n;j++)
            sol[i][j]=0;
        }

      bool queens=place_queens(sol,0,n);
}



