#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

void bubble_sort(int a[],int n)
{
   for(int i=0;i<n;i++)
      for(int j=0;j<n-i-1;j++)
      if(a[j]>a[j+1])
      swap(a[j],a[j+1]);
}
int main()
{
   int n,key;
  cin>>n;

   //worst case
   for(int i=0;i<n;i++)
      a[i]=n-1;

    time_t s=clock();
    bubble_sort(a,n);
    time_t e=clock();

    cout<<"Bubble Sort took"<<e-s<<endl;
}
