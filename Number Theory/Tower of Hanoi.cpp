
//move all discs from a to c
//move one disk at a time
//cant place big disc on small
#include <iostream>
using namespace std;
void move_(int n,char source,char helper,char destination)
{
   if(n==0)
   return;
   //move n-1 disc from source to helper
   //destination becomes b
   move_(n-1,source,destination,helper);
   cout<<" Shift disc "<<n<<"th from "<<source<<" to "<<destination<<endl;
   move_(n-1,helper,source,destination);
}
int main()
{
   int n;
   cin>>n;
   move_(n,'a','b','c');
}
