#include <iostream>
using namespace std;

void prime_sieve(int a[],int n)
{
    for(int i=3;i<n;i+=2)
        a[i]=1;
    for(int i=3;i<n;i+=2)
    {
        if(a[i]==1)
        for(int j=i*i;j<n;j+=i)
            a[j]=0;
    }
    a[2]=1;
}

int main()
{
    //generate all prime numbers till n;
    int n;
    cin>>n;
    n=n+1; //because pehle wala 0 hai
    int a[n]={0};
    prime_sieve(a,n);
    for(int i=0;i<n;i++)
        if(a[i]==1)
        cout<<i<<" ";
}
