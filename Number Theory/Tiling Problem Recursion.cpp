/*
Given, a wall of size 4XN, and tiles of size (1X4) and (4X1).
In how many ways can you build the wall?
*/

#include <iostream>
using namespace std;

int tiling(int n)
{
   if(n==1)
      return 1;
   if(n==2)
      return 1;
   if(n==3)
      return 1;
   return tiling(n-1)+tiling(n-4);
}

int main()
{
   int n;
   cin>>n;
   cout<<tiling(n);
}
