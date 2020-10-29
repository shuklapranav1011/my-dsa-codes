//hulk can jump in power of 2
//find least steps
#include <iostream>
#include <math.h>
using namespace std;

//M-1 for hulk jumping in any given powers of a integer p
/*
int least_power(int p,int n)
{
    int pow=0;
    while(pow(p,n)<=n)
    {
        pow++;
    }
    return pow-1;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    int beg=0;
    int last=n;
    int jump=0;
    while(beg<last)
    {
        int mid=last-beg;
        beg=beg+(pow(2,least_power(2,n); //because hulk can jump only in powers of two
        jump++;
    }
    cout<<jump<<endl;
    }
}
*/


//note that it is given that hulk can only jump in power of 2
//lets utilize this

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        //now in the binary form of n, the places containing 1 are the levels where hulk can jump
        //thus, this is counting number of set bits to calculate where hulk has jumped
        cout<<__builtin_popcount(n)<<endl;
    }
}



























