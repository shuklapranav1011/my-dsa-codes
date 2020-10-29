#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool compare(int a,int b){
   return a>b;
}
int main()
{
   int cases;
   cin>>cases;
   while(cases--)
   {
   int n,k;
   cin>>n>>k;
   vector<int> p; p.reserve(n);
   for(int i=0;i<n;i++)
      {
         int x; cin>>x;
         if(k%x==0)
            p.push_back(x);
      }
   sort(p.begin(),p.end(),compare);
   if(p.size()==0)
      cout<<-1;
   else
      cout<<p[0];

   p.clear();
   }
}
