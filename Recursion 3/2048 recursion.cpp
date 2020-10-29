//2048 --> two zero four eight

#include <iostream>
#include <strings.h>
using namespace std;
void stonum(string a[],int n)
{
   if(n==0)
      return;
   stonum(a,n/10);
   cout<<a[n%10]<<" ";
}
int main()
{
   int n;
   cin>>n;
   string a[]={"zero","one","two","three","four","five","six","seven","eight","nine"};
   stonum(a,n);
}

