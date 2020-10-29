/*a thief enters a shop containing 4 items.
a bag - 1 kg - 40Rs.
a ball - 2 kg - 20Rs.
a ball - 3 kg - 35Rs.
a bat  - 5 kg - 100Rs.

Thief has bag of capacity 7kg.
What is the maximum profit he can make?
*/
#include <iostream>
using namespace std;
int max_profit=0;

//traversing right to left
int profit(pair<int,int> *in,int n,int c)
{
   if(n==0 || c==0)
      return 0;
   //including curr_items
   //weight of first less than capacity
   int inc=0,exc=0,ans=0;
   if(in[n].first<=c)
         inc=in[n-1].second + profit(in,n-1,c-in[n-1].first);
   //excluding curr_items
   exc=profit(in,n-1,c);
   ans=max(inc,exc);
   return ans;
}

int main()
{
   int n=4;
   pair <int,int>  items[]={make_pair(1,40),make_pair(2,20),make_pair(3,35),make_pair(5,100)};
   int capacity=7;
   //(weight,cost)
   cout<<profit(items,n,capacity);
}
