//The given array will be of the type [4,5,1,2,3] and you have to search for
//an element without sorting the array.


#include <iostream>
using namespace std;
int main()
{
    int n; cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }cout<<endl;

    int ele;cin>>ele;
    int flag=0;
    int beg=0,last=n-1;int mid;
    while(beg<=last)
    {
        mid=(beg+last)/2;
        if(a[mid]==ele)
        {
            flag=1;
            break;
        }
        else if(a[beg]<=a[mid])
        {
            if(ele<a[mid]&&ele>=a[beg])//imp
                last=mid-1;
            else
                beg=mid+1;
        }
        else
        {
            if(ele>a[mid]&&ele<=a[last])//imp
                beg=mid+1;
            else
                last=mid-1;
        }
       }

        if(flag==1)
        cout<<endl<<mid;
}
