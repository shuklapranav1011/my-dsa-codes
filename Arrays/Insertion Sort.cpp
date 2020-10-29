#include <iostream>
using namespace std;
void insertion_sort(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        int e=a[i];
        int j;
        for(j=i-1; j>=0&&a[j]>e ;j--)
        {
            a[j+1]=a[j];
        }
        a[j+1]=e;
    }
}
