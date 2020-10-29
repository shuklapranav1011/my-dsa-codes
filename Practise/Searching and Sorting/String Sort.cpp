#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool compare(string a,string b)
{
   if(a.find(b)==0 || b.find(a)==0)
   {
         return a.length()>b.length();
   }
   else
   {
      return a<b;
   }
}

int main()
{
   int n;
   cin>>n;
   string a[n];
   for(int i=0;i<n;i++)
      cin>>a[i];

   sort(a,a+n,compare);

    for(int i=0;i<n;i++)
      cout<<a[i]<<endl;

}
