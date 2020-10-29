//in an array of length n
//find all the sub-arrays divisible by N

#include <iostream>
using namespace std;

#define ll long
ll a[1000000], pre[1000000]={0};
int main()
{
      int n;
     cin>>n;
      // pre contains the bu
      pre[0]=1;
      int sum=0;
      for(int i=0;i<n;i++)
      {
         cin>>a[i];
         sum=sum+a[i];
         sum=sum%n;
         //now sum is b/w 0 to n-1
         //but what if sum is a -ve number
         sum=(sum+n)%n;
         //3%5 and (3+5)%5 are equal;
         pre[sum]++;
      }
      int cnt=0;
      for(int i=0;i<n;i++)
      {
         int m=pre[i];
         cnt+=(m*(m-1));//mC2;
      }
      cout<<cnt<<endl;
}
