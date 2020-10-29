//given an array containing all numbers repeated twice except for two numbers.
//find those two numbers.
//do not use any extra space.
//solve in linear time.

#include <iostream>
#include <vector>
#include <algorithm>
#include "bit_functions.h"
using namespace std;
int get_last_set_bit_pos(int n)
{
    int c=1;
    while(n>0)
    {
        if((n&1)==1)
            return c;
            n=n>>1;
            c++;
    }
}
int main()
{
    int n;
    cin>>n;
    vector<int>a;
    a.reserve(n);
    int k=0;
    for(int i=0;i<a.size();i++)
        {
            int no;
            cin>>no;
            a.push_back(no);
            k=k^no;
        }
    sort(a.begin(),a.end());
    int ele=0;
    k=get_last_set_bit_pos(k);

    int no1=0;
    int no2=0;

    bit b;
    for(int i=0;i<n;i++)
    {
        if(b.getBit(n,k)==1)
        {
            no1=no1^a[i];
        }
        if(b.getBit(n,k)==0)
        {
            no2=no2^a[i];
        }
    }
    if(no1>no2)
        cout<<no1<<" "<<no2<<endl;
    else
        cout<<no2<<" "<<no1<<endl;
}











