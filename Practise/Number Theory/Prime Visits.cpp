//find number of prime numbers in a given range.
//range a to b
//number of queries n
//n<=1000  a and b <=100000

//i/p
//2
//1 10
//11 20

 //o/p
 //4
 //4

#include <iostream>
#include <cmath>
using namespace std;

void prime_sieve(int *a)
{
   long long i,j;
   for(i=3;i<=100000;i+=2)
      a[i]=1;
   for(i=3;i<=10000;i+=2)
   {
      if(a[i]==1)
         for( j=i*i;j<=100000;j=j+i)
            a[j]=0;
   }
   a[0]=a[1]=0;
   a[2]=1;
}

int main()
{
   long long n;   cin>>n;
   int p[100000]={0};
   prime_sieve(p);
   long long a,b;
   //taking b>a
   while(n--)
   {
      int c=0;
     cin>>a>>b;
     for(int i=a;i<=b;i++)
     {
        if(p[i]==1)
            c++;
     }
     cout<<c<<endl;
   }
}
