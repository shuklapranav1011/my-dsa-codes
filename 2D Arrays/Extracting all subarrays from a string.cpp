//AIM--Find cumulative sum of all sub-arrays.

//BRUTE FORCE SOLUTION
/*In this method we can find each sub-array and its sum.*/

#include <iostream>
using namespace std;

/*
void extract_subarray_sum()
{
int m,n;
    cout<<"Enter limits"<<endl;
    cin>>m>>n;

    int a[m][n];
    cout<<"Enter Array"<<endl;



    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];

        }
    }

    cout<<endl;
    int s=0;int t;
    //Extracting all top-left (i,j)
for(int i=0;i<m;i++)
{
    for(int j=0;j<n;j++)
    {
        //Extracting all bottom right (k,m)
        for(int k=i;k<m;k++)
        {
            for(int l=j;l<n;l++)
            {
                for(int g=i;g<=k;g++)
                {
                    for(int h=j;h<=l;h++)
                    {
                         s=s+a[g][h];

                    }

                }

            }
        }
    }
}

cout<<"Final sum of all sub-arrays = "<<s<<endl;
}
 */



//OPTIMIZATION METHOD 1
/*In this method we can find the sum of each subarray in a matrix*/


void extract_subarray_sum()
{
    int m,n;
    cout<<"Enter limits"<<endl;
    cin>>m>>n;

    int a[m][n];
    cout<<"Enter Array"<<endl;

    long long t=0;

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];

        }
    }

    cout<<endl;

    //t stores sum of all 1*1 sub-matrices

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    //Extracting prefix sum matrix

    //Row-wise prefix sum
    long long s;

    for(int i=0;i<m;i++)
    {
        s=0;
        for(int j=0;j<n;j++)
        {
            s=s+a[i][j];
            a[i][j]=s;
        }
    }

    cout<<endl;

    //Column-wise prefix sum

    for(int j=0;j<n;j++)
    {
        s=0;
        for(int i=0;i<m;i++)
        {
            s=s+a[i][j];
            a[i][j]=s;
        }
    }

    cout<<endl;

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    /*
    Now the matrix a[][],
    an element a[i][j] contains sum of all elements from (0,0) to (i,j).

    To calculate any subarray
    i.e sum from top-left(i,j) to bottom-right(k,l)
                       = a[k][l]- a[i-1][l]- a[k][j-1]+ a[i-1][j-1]
                       */

    s=0;

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=i;k<m;k++)
            {
                for(int l=j;l<n;l++)
                {
                        if(i==0&&j==0)
                        {
                            s=s+a[k][l];
                        }
                        else if(i==0&&j!=0)
                        {
                            s=s+a[k][l]-a[k][j-1];
                        }
                        else if(i!=0&&j==0)
                        {
                            s=s+a[k][l]-a[i-1][l];
                        }
                        else
                        {
                            s=s+a[k][l]-a[i-1][l]-a[k][j-1]+a[i-1][j-1];
                        }

                }
            }
        }

    }
   cout<<"Final sum of all sub-arrays = "<<s<<endl;
}



//OPTIMIZATION METHOD 2
/* In this method we calculate the contribution of each element in the total
sum of all subarrays. We calculate the */


/*
void extract_subarray_sum()
{

    int m,n;
    cout<<"Enter limits"<<endl;
    cin>>m>>n;

    int a[m][n];
    cout<<"Enter Array"<<endl;

    long long t=0;

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];

        }
    }

    cout<<endl;

    long long s=0;
    int top_left_contri;
    int bottom_right_contri;

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {

                top_left_contri= (i+1) * (j+1);
                bottom_right_contri= (m-i) * (n-j);

            s=s+(a[i][j]*(top_left_contri*bottom_right_contri));
        }
    }

    cout<<"Final sum of all sub-arrays = "<<s<<endl;
}
*/

int main()
{
    extract_subarray_sum();
}



























