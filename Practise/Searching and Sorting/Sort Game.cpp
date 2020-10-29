#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool compare(pair<string,int> a,pair<string,int> b)
{
   if(a.second==b.second)
   {
      return a.first< b.first;
   }
   else
   {
      return a.second>b.second;
   }
}

int main()
{
   int x;
   cin>>x;
   int n;
   cin>>n;
   pair<string, int> a[n];
   for(int i=0;i<n;i++)
      {
         cin>>a[i].first;
         cin>>a[i].second;
      }

    sort(a,a+n,compare);

    for(int i=0;i<n;i++)
      {
         if(a[i].second>=x)
         cout<<a[i].first<<" "<<a[i].second<<endl;
      }
}
