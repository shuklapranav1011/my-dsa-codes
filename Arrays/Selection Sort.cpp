#include <iostream>
using namespace std;
void selection_sort(int n, int a[])
{
    for(int i=0;i<n-1;i++)
    {
        int min_index=i;
        for(int j=i;j<n;j++)
        {
            if(a[j]<a[min_index])
            {
                j=min_index;
            }
        }
        swap(a[i],a[min_index]);
    }
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}
int main()
{
    int a[]={1,4,3,5,2};
    selection_sort(5,a);
}
