//Making linear search generic

#include <iostream>
#include <cstring>
using namespace std;

template<typename T>
int search_(T arr[],int n,T key)
{
   for(int p=0;p<n;p++)
      if(a[p]==key)
      return p;

   return n;
}

template<class ForwardIterator, class T>
ForwardIterator search__(ForwardIterator s, ForwardIterator e, T key)
{

}


int main()
{
   int a[]={1,2,3,4,5,6,7};
   int n=sizeof(a)/sizeof(int);
   int key=10;

   cout<<search_(a,n,key)<<endl;

   float b[]={1.1,1.2,1.3};
   float key=1.2;
   cout<<search_(b,3,1.3);

   cout<<search_(a,n,key)<<endl;
}
