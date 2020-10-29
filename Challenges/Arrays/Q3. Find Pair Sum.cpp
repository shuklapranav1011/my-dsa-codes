#include <iostream>
#include <algorithm>
using namespace std;

void find_pair_sum(int *a,int n,int ele)
{
    cout<<endl;

    sort(a,a+n);

    int beg=0;
    int last=n-1;
    bool flag=false;
    while(beg<last)
    {  int k=a[beg]+a[last];
        if(k<ele)
            beg++;
        else if(k>ele)
            last--;
        else if(k==ele)
            {
                flag=true;
                cout<<a[beg]<<" and "<<a[last]<<endl;
                beg++;//to prevent infinite loop
            }
    }

    if(flag==false)
    cout<<"No pair sum";

}

int main()
{
    int n;
    cin>>n;
    int *a=new int[n];

    for(int i=0;i<n;i++)
    cin>>a[i];

    int ele;
    cin>>ele;

    find_pair_sum(a,n,ele);

    delete []a;
}
