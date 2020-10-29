#include <iostream>
#include <algorithm>
using namespace std;
bool binary_search_recursion(int beg,int last,int *p,int ele)
{
   if(beg>last)
      return false;
   int mid=(beg+last)/2;
   if(p[mid]==ele)
      return true;
   else if(p[mid]<ele)
       return binary_search_recursion(mid+1,last,&p[0],ele);
   else
      return binary_search_recursion(beg,mid-1,&p[0],ele);
}
int main()
{
   int n;
   cin>>n;
   int ele;
   cin>>ele;
   int a[n];
   for(int i=0;i<n;i++)
      cin>>a[i];
   sort(a,a+n);
   cout<<binary_search_recursion(0,n,a,ele);
}
