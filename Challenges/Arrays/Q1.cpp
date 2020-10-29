//Maximum value in an array

#include <iostream>
using namespace std;

int main()
{

    cout<<endl;
    int n; cin>>n;
    long long a[n];
    int s=INT_MIN;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]>s)
            s=a[i];
    }
    cout<<s;
}
