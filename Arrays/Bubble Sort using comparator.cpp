#include <iostream>
#include <algorithm> //for using STL

using namespace std;

bool comparator(int a,int b)
{
    return a>b; //This is used for sorting array in descending order
}

void(int arr[],int n, bool(&cmp)(int a,int b))
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(cmp(arr[j],arr[j+1])==true)
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

void sort_array(int arr[],int n) //using STL function to solve algorithm
{
    sort(a,a+n,compare);
}

