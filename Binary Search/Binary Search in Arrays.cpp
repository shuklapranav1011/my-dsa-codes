#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int a[]={1,3,2,5,7,4,5,2,3};
    int n=sizeof(a)/sizeof(int);
    cout<<n<<endl;
    sort(a,a+n);
    int ele;    cin>>ele;
    int beg=0;  int last=n-1;
    int flag=0;
    while(beg<=last)
    {   int mid=(beg+last)/2;
        if(a[mid]==ele)
        {
            flag=1;
            break;
        }
        else if(a[mid]>ele)
        {
            last=mid-1;
        }
        else if(a[mid]<ele)
        {
            beg=mid+1;
        }
    }
    if(flag==1)
        cout<<"Element found";
    else
        cout<<"Element not found";
}

