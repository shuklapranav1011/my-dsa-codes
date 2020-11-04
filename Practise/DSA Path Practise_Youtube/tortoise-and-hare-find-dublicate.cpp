#include <bits/stdc++.h>
using namespace std;

/*
First of all, where does the cycle come from? Let's use the function f(x) = nums[x] to construct the sequence: x, nums[x], nums[nums[x]], nums[nums[nums[x]]], ....

Each new element in the sequence is an element in nums at the index of the previous element.

If one starts from x = nums[0], such a sequence will produce a linked list with a cycle.
*/

int findDuplicateNoExtraSpace(vector<int>& arr) {
        
      int tortoise=arr[0];
      int hare=arr[0];

      do{
         tortoise= arr[tortoise];
         hare= arr[arr[hare]];
      }while(tortoise!=hare);

      tortoise=arr[0];
      while(tortoise!=hare){
         tortoise=arr[tortoise];
         hare=arr[hare];
      }

      return hare;
}

int main(int argc, char const *argv[])
{
   #ifdef ONLINE_JUDGE
   freopen("intput.txt" , "r" , stdin);
   freopen("output.txt" , "w" , stdout);
   #endif

   vector<int> a= {1,3,4,2,2};
   cout<<findDuplicate(a);

   return 0;
}



