//Given string s, find all permutations of the string s
//but do not repeat any permutations
//aba - baa baa gets repeated
#include <iostream>
#include <set>
#include <string>
using namespace std;

void permutation(char *in,int i,set <string> &s)
{
   if(in[i]=='\0')
   {
      string t(in);
      s.insert(t); // set will maintain only the unique strings
      return;
   }

   //using curr_ele
   permutation(in,i+1,s);

   //using curr_ele + 1
   if(in[i+1]!='\0')
   {
      swap(in[i],in[i+1]);
      permutation(in,i+1,s);
      //backtracking
      swap(in[i],in[i+1]);
   }

   //using curr_ele +2
   if(in[i+2]!='\0')
   {
      swap(in[i],in[i+2]);
      permutation(in,i+1,s);
      //backtracking
      swap(in[i],in[i+2]);
   }
}

int main()
{
   char a[100];
   cin>>a;
   set <string> s;
   permutation(a,0,s);
   for(auto str:s)
      cout<<str<<endl;
}
