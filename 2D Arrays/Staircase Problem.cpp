

/*The given 2D array is sorted both row and column-wise.
Find a given element in such an array.
*/

#include <iostream>
using namespace std;

int main()
{
    int m,n,ele;
    cout<<"Enter limits and ele";
    cin>>m>>n>>ele;
    int a[m][n];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }

    int i=0,j=n-1;
    bool flag=false;
    while(j>=0)
    {
        if(a[i][j]==ele)
            {
                flag=true;
                break;
            }
        else if(a[i][j]>ele)
        {
            i++; //check previous row
        }
        else if(a[i][j]<ele)
        {
            j--;//check the previous column
        }
    }

    if(flag)
        cout<<"Found";
    else
        cout<<"Not Found";
}
