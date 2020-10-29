#include <iostream>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;
int main()
{
   int cost[3];
   for(int i=0;i<3;i++)
      cin>>cost[i];
   int maxArea[3];
   for(int i=0;i<3;i++)
      cin>>maxArea[i];
   int minStore[3][2];
   for(int i=0;i<3;i++)
      for(int j=0;j<2;j++)
         cin>>minStore[i][j];
   int totCost;
   cin>>totCost;
   int val[3]={0};
   int m=INT_MAX;
   for(int i=0;i<3;i++)
      m=min(m,cost[i]);
   int a;
   for(int i=0;i<3;i++)
   {
      if(m==cost[i])
      {
         val[0]=maxArea[i]*m;
         a=maxArea[i];
         break;
      }
   }
   m=INT_MIN;
   for(int i=0;i<3;i++)
      m=max(m,cost[i]);
   int b;
   for(int i=0;i<3;i++)
   {
      if(m==cost[i])
      {
         val[1]=minStore[i][0]*minStore[i][1]*cost[i];
         b=minStore[i][0]*minStore[i][1];
         break;
      }
   }
   int c=totCost-a-b;
   sort(cost,cost+3);
   val[2]=c*cost[1]; //cost[1] was left to unused
   cout<<val[0]+val[1]+val[2];
}
