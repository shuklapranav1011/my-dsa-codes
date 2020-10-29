#include <iostream>
#include <algorithm>
using namespace std;
/*
int main()
{
    long long n;cin>>n;
    int a[3*n];
    long long i=0;
    for(;i<n;i++)
       {
        cin>>a[i];
        a[i+n]=a[i];
        a[i+(2*n)]=a[i];
       }

    for(i=0;i<n;i++)
       {
       if(a[i]==0)
        cout<<a[i]<<endl;
       }
    for(i=n;i<2*n;i++)
       {
       if(a[i]==1)
        cout<<a[i]<<endl;
       }
    for(i=2*n;i<3*n;i++)
       {
       if(a[i]==2)
        cout<<a[i]<<endl;
       }

}
*/

int main()
{
    long long n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];

    int l=0,m=0,h=n-1;
    while(m<h)
    {
        if(a[mid]==0)
        {
            swap(a[low],a[mid]);
            low++;
            mid++;
        }
        else if(a[mid]==1)
            mid++;
        else if(a[mid]==2)
        {
            swap(a[mid],a[high]);
            mid++;high--;
        }
    }
    for(int i=0;i<n;i++)
        cout<<a[i]<<endl;
}
