//SLIDING WINDOW APPROACH -1

//Given an array and an integer k, find maximum for each and every
//every contiguous sub-array of size k.

//eg.
//9
//1 2 3 1 4 5 2 3 6
//3

//o/p
//3 3 4 5 5 5 6

#include <iostream>
#include <deque>
using namespace std;

void slider_window_method(int *a,int n,int k)
{
   deque <int> q(k);

   //we process first k elements separately
   int i;
   for(i=0;i<k;i++)
   {
      while(!q.empty()&&a[i]>=a[q.back()])
         q.pop_back();

      q.push_back(i);
   }
   cout<<a[q.front()]<<" ";

   //processing rest of the elements
   for(;i<n;i++)
   {
      //moving window forward
      //contraction - removing less than i-k indexes
      while(!q.empty()&&q.front()<i-k)
         q.pop_front();

      //removing unwanted elements inside the window
      while(!q.empty()&&a[i]>=a[q.back()])
         q.pop_back();

      //adding elements to the window
      q.push_back(i);

      //printing the window max.
      cout<<a[q.front()]<<" ";
   }
}
int main()
{
   int a[100000];
   int n;
   cin>>n;
   for(int i=0;i<n;i++)
   {
      cin>>a[i];
   }
   int k;
   cin>>k;

   slider_window_method(a,n,k);
}

