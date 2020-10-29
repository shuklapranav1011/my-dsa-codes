#include <iostream>
using namespace std;
//generate balanced pairs of round brackets using N pairs of round brackets
void generate_brackets(int n,char *b,int i,int open,int close)
{
    if(i==2*n)
    {
       b[i]='\0';
       cout<<b<<endl;
       return;
    }
    //bracket open
    if(open<n)
      {
         b[i]='(';
         generate_brackets(n,b,i+1,open+1,close);
      }
    //bracket close
    if(close<open)
    {
       b[i]=')';
       generate_brackets(n,b,i+1,open,close+1);
    }
}
int main()
{
   int n;
   cin>>n;
   char a[2*n];//brackets are in pairs and last character = '\0'
   generate_brackets(n,a,0,0,0);
}
