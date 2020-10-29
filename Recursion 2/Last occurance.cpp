//longer method to help understand recursion
#include <iostream>
#include <vector>
using namespace std;
int last_occurance(int a[],int n,ele)
{
   if(n==0)
      return -1;
   int i=last_occurance(a+1,n-1,ele);
   if(i==-1)
   {
      if(a[0]==key)
         return 0;
      else
         return -1;
   }
   return i+1;
}

int first_occurance(int a[],int n,int ele)
{
   if(n==0)
      return -1;
   if(a[0]==ele)
      return 0;
   int i=first_occurance(a+1,n-1,ele);
   if(i==-1)
      return -1;
   return i+1;
}

vector<int> all_occurance(int a[],int i,int n,int ele)
{
   vector <int> o;
   if(n==0)
      return o;
   if(a[i]==ele)
      o.push_back(i);
   all_occurance(a,i+1,n-1,ele);
}
int main()
{
   int n;
   cin>>n;
   int a[n];
   for(int i=0;i<n;i++)
      cin>>a[i];
      int ele;
      cin>>ele;

      cout<<last_occurance(a,n,ele);
}
