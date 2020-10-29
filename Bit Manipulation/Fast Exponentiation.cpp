#include <iostream>
using namespace std;

int main()
{
    int a;
    int b;
    cin>>a>>b;
    //to calculate a to power b
    //in logN time
    int pow=1;
    while(b>0)
    {
        int last_bit=b&1;
        if(last_bit)
        {
            pow=pow*a;
        }
        a=a*a;
        b>>1;
    }
    cout<<pow<<endl;
}
