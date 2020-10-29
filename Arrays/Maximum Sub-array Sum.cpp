/*Maximum Sub-array Sum*/
#include <iostream>
using namespace std;

void maximum_subarray_sum(int a[],int n)
{
    int current_sum=0,final_sum=0,last=0,beg=0;
    for(int i=0;i<n;i++)
    {
        current_sum=0;

        for(int j=i;j<n;j++)
        {
            current_sum=current_sum+a[j];
            if(current_sum>final_sum)
            {
                final_sum=current_sum;
                last=j;
                beg=i;
            }
        }
    }
    cout<<"Subarray with maximum sum is \n";

    for(int i=beg;i<=last;i++)
    {
        cout<<a[i]<<",";
    }

}

int main()
{
    int n;
    cout<<"Enter array limit";
    cin>>n;
    int a[n];
    cout<<"Input Array";
    for(int i=0;i<n;i++)
    {
       cin>>a[i];
    }

    maximum_subarray_sum(a,n);
}
