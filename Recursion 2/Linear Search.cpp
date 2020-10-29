//return occurrance also
#include <iostream>
using namespace std;
int * linear_search(int *p,int n,int ele)
{
   if(n==0)
      return nullptr;
   if(p[0]==ele)
   {
      return &p[0];
   }
   return linear_search(&p[1],n-1,ele);
}
int main()
{
   int n,ele;
   cin>>n;
   int a[n];
   for(int i=0;i<n;i++)
      cin>>a[i];
   cin>>ele;
   int *p=linear_search(a,n,ele);
   if(p!=nullptr)
      cout<<(p-a);
}
