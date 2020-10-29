#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int arr[]={1,4,3,5,6,4,5,7,5,7,2,4,3,5,6,7,8,6,4,2,98,7,3,3,5,4,6,3,6,8,6,7,5,9,0,0,4,2,3};
    int n=sizeof(arr)/sizeof(int);
    cout<<n<<endl;

    sort(arr,arr+n);
    for(int i=0;i<n;i++)
    {
    cout<<arr[i]<<" ";
    }cout<<endl;

    int ele;cin>>ele;

    if(binary_search(arr,arr+n,ele)==true)
    {
        //first occurrence
        int beg=0;int last=n-1; int ans;
        while(beg<=last)
        {int mid=(beg+last)/2;
            if(arr[mid]==ele)
            {
                ans=mid;
                last=mid-1;
            }
            else if(arr[mid]>ele)
            {
                last=mid-1;
            }
            else if(arr[mid]<ele)
            {
                beg=mid+1;
            }
        }
        cout<<"first occurrence is "<<ans<<endl;

        //last occurrence
        beg=0;last=n-1;
        while(beg<=last)
        {int mid=(beg+last)/2;
            if(arr[mid]==ele)
            {
                ans=mid;
                beg=mid+1;
            }
            else if(arr[mid]>ele)
            {
                last=mid-1;
            }
            else if(arr[mid]<ele)
            {
                beg=mid+1;
            }
        }
        cout<<"last occurrence is "<<ans<<endl;
    }
    else
    {
        cout<<"Element not found";
    }
}
