#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    //Indian Money Change
    int money;
    cout<<"Enter amount";
    cin>>money;
    int coin[]={1,2,5,10,20,50,100,200,2000};
    int n=sizeof(coin)/sizeof(int);
    while(money!=0)
    {
        int m=coin[upper_bound(coin,coin+n,money)-coin-1];
        money=money-m;
        cout<<m<<",";
    }
    return 0;
}
