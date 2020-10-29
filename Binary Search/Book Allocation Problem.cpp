#include <iostream>
#include <algorithm>
using namespace std;

bool max_page(int p[],int n,int m,int mpage)
{
    int curr_page=p[0];
    int c=1;
    for(int i=1;i<n;i++)
    {
        if(curr_page+p[i]<=mpage)
        {   curr_page+=p[i];
        }
        else
        {   curr_page=p[i];
            c++;
        }
    }
    if(c<=m)
        return true;
    else
        return false;
}

int main()
{
    int n;//books
    cin>>n;
    int m;//students
    cin>>m;
    int page[n];//pages in each book
    for(int i=0;i<n;i++)
        cin>>page[i];
    sort(page,page+n);//books in ascending order of number of pages

    for(int i=0;i<n;i++)
        cout<<page[i]<<" ";
        cout<<endl;

    int beg=page[n-1];//best case maximum pages read by a student
    int last=0;
    for(int i=0;i<n;i++)
        last=last+page[i];
    cout<<last<<endl;
    //last= worst case maximum number of pages read by a student

    //to minimize maximum number of pages read by a student

    int ans=0;
    while(beg<=last)
    {
        int mid=(beg+last)/2;
        cout<<mid<<endl;
        if(max_page(page,n,m,mid)==true)
        {
            ans=mid;
            cout<<mid<<" is possible"<<endl;
            last=mid-1;
        }
        else
            beg=mid+1;
    }
    cout<<ans;

}
