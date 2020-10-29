#include <iostream>
using namespace std;

int power(int x,int n)
{
    if(n==0)
        return 1;
    return x*power(x,n-1);
}

int main()
{
    int x,n;
    cin>>x>>n;

    /*
    //M-1 Recursive
    cout<<power(x,n)<<endl;
    */


    //M-2 Bit masking
    int val=1;
    while(n>0)
    {
        int last_bit=n&1;
        if(last_bit==1)
            val=val*x;
        x=x*x;
        n=n>>1;
    }
    cout<<val<<endl;
}



















