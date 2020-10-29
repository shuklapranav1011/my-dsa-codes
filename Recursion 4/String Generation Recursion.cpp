/*
given: 1-A , 2-B, ............, 26-Z

input : 1234
output : ABCD, LCD, AWD
*/

#include <iostream>
#include <string>
using namespace std;
void generate_strings(char *in,char *out,int i,int j)
{
      //base case
      if(in[i]=='\0')
      {
         out[j]='\0';
         cout<<out<<endl;
         return;
      }

      int digit; char ch;
      digit=(in[i]-'0');
      //first coupled with second
      if(in[i+1]!='\0')
      {
         int digit2=(digit*10)+(in[i+1]-'0');
         if(digit2<=26)
         {
            ch=digit2+64;
            out[j]=ch;
            generate_strings(in,out,i+2,j+1);
         }
      }
      //first not coupled with second
      ch=digit+64;
      out[j]=ch;
      generate_strings(in,out,i+1,j+1);

}


int main()
{
   char in[10000];
   cin>>in;
   char out[100000];
   generate_strings(in,out,0,0);
}

























