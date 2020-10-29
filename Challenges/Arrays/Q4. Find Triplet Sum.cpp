#include <iostream>
#include <algorithm>
using namespace std;

int remove_duplicate_from_an_array_and_return_new_length(int *a,int n)
{
    sort(a,a+n);
    int prev=0;
    for(int current=1;current<n;current++)
    {
       if(a[current]!=a[prev])
       {
           prev++;
       }
       a[prev]=a[current];
    }
    return prev;
}

void find_triplet_sum(int *a,int n,int ele)
{
    sort(a,a+n);
    n=remove_duplicate_from_an_array_and_return_new_length(a,n);
    if(n<3||n>1000)
    {
        cout<<"No Triplet Possible";
    }
    else
    {
    int beg=0;
    int last=n-1;
    bool flag=false;

   while(beg<last)
   {

    int k=a[beg]+a[last];

    if(k>=ele)
        {
            last--;
            beg=0;
        }
    else if(k<ele)
    {
        int l=ele-k;
        for(int i=beg+1;i<last;i++)
            if(a[i]==l)
            {
                flag=true;
                cout<<a[beg]<<", "<<a[i]<<" and "<<a[last]<<endl;
                break;
            }

        beg++;
     }
   }

   if(flag==false)
    cout<<"No Triplet Possible";
    }
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

    find_triplet_sum(a,n,ele);

    delete []a;
}
