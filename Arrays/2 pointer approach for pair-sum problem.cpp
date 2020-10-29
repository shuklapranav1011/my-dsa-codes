/* Pair sum problem
Given a SORTED Integer Array,
find the number of pairs whose sum is equal to a user defined integer K.*/

#include <iostream>
#include <algorithm>

using namespace std;

 void pair_sum(int a[],int n)
 {
     cout<<"Enter the pair-sum";
     int ele;
     cin>>ele;
//Remember that the integer array is sorted.
//The two pointer approach only works on sorted arrays.

     sort(a,a+n);

     int beg=0,last=n-1;

   while(beg<last) ////////
     { int sum=(a[beg]+a[last]);

     //ARRAY is sorted.
         if(sum>ele)
         {
          last-=1;
         }
         else if(sum<ele)
         {
             beg+=1;
         }
         else
         {
             cout<<"pair is ("<<a[beg]<<","<<a[last]<<") ";
         }
     }

 }
