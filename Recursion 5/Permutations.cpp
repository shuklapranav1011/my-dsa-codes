//Given string s, find all permutations of the string s

#include <iostream>
using namespace std;

void permutation(char *in,int i)
{
   if(in[i]=='\0')
   {
      cout<<in<<endl;
      return;
   }

   //using curr_ele
   permutation(in,i+1);

   //using curr_ele + 1
   if(in[i+1]!='\0')
   {
      swap(in[i],in[i+1]);
      permutation(in,i+1);
      //backtracking
      swap(in[i],in[i+1]);
   }

   //using curr_ele +2
   if(in[i+2]!='\0')
   {
      swap(in[i],in[i+2]);
      permutation(in,i+1);
      //backtracking
      swap(in[i],in[i+2]);
   }
}

int main()
{
   char a[100];
   cin>>a;
   char out[100];
   permutation(a,0);
}
