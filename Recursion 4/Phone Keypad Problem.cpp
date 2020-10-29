#include <iostream>
#include <cstring>
using namespace std;
char keypad[][10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
void f(char *in,char *out,int i,int j)
{
   if(in[i]=='\0')
   {
      out[j]='\0';
      cout<<out<<endl;
      return;
   }

   int digit=in[i]-'0';

   if(digit==1 || digit ==0)
      f(in,out,i+1,j);

   for(int k=0;keypad[digit][k]!='\0';k++)
   {
      out[j]=keypad[digit][k];
      f(in,out,i+1,j+1);
   }
}

int main()
{

   char in[1000000];
   cin>>in;
   char out[100000];
   f(in,out,0,0);
}
