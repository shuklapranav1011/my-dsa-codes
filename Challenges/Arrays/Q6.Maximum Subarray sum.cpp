#include <iostream>
using namespace std;

int max_sum_subarray(long long *a,long long n)
{
    long long s=0;long long k=0;
    for(long long i=0;i<n;i++)
    {
        s+=a[i];

        if(s<0)
            s=0;

        k=max(k,s);
    }
    return k;
}

int main()
{
    long long n;
    int t;
    long long *a;
    cout<<"Enter number of test-cases";
    cin>>t;

    for(int i=0;i<t;i++)
    {
        cout<<"Enter length of array"<<endl;
        cin>>n;
        cout<<"Enter array elements";
        a=new long long[n];

        for(long long i=0;i<n;i++)
            cin>>a[i];

        cout<<max_sum_subarray(a,n);

        delete[]a;
    }
}
