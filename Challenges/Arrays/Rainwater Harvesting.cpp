#include <iostream>
#include <algorithm>
using namespace std;

int max_ele(int *a,int n)
{   int s=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]>s)
            s=a[i];
    }
    return s;
}

int min_ele(int *a,int n)
{   int s=a[0]; //a[i] always greater than 0
    for(int i=0;i<n;i++)
    {
        if(a[i]<s)
            s=a[i];
    }
    return s;
}

int water_at_level_h(int *a,int n,int h)
{
    int beg;
    int last;
    for(int i=0;i<n;i++)
    {
        if(a[i]==h)
            {
                beg=i;break;
            }
    }
    for(int i=n-1;i>=0;i--)
    {
        if(a[i]==h)
        {
            last=i;break;
        }
    }

    int water_collected=0;
         for(int i=beg;i<last;i++)
         {
             if(a[i]<h)
                water_collected++;
         }

    return water_collected;
}

void rainwater_harvesting(int *a,int n)
{
    cout<<endl;
    int water_collected=0;
    int height_max=max_ele(a,n);
    int height_min=min_ele(a,n);

    int current_height;

    for(int current_height=height_min+1;current_height<=height_max;current_height++)
    {
        water_collected+=water_at_level_h(a,n,current_height);
    }

    cout<<water_collected<<endl;
}

int main()
{
    int n;
    cin>>n;
    int *a=new int[n];

    for(int i=0;i<n;i++)
    cin>>a[i];

    rainwater_harvesting(a,n);

    delete []a;
}
