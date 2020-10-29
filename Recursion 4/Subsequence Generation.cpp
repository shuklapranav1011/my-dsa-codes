//Important
//given a string containing n characters
//find out the all subsets of that string.

//eg; "abc"
//["", "a", "b", "c", "ab", "ac", "bc", "abc"]

#include <iostream>
using namespace std;

void generate_subsequence(char *in,char *out,int i,int j)
{
   if(in[i]=='\0')
     {
            out[j]='\0';
            cout<<out<<endl;
            return;
     }
   //rec case
   //include curr_char
   out[j]=in[i];
   generate_subsequence(in,out,i+1,j+1);
   //exclude curr_char
   generate_subsequence(in,out,i+1,j); //the curr value of out[j] will be overwritten
}

int main()
{
   char input[]="abc";
   char output[10];
   generate_subsequence(input,output,0,0);
}
