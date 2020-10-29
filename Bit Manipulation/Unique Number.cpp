//given a list where every number occurs twice except one, find it
//do not store all the numbers
//note that all the numbers occur twice
//a^a^b=b

#include <iostream>
using namespace std;
int main()
{
    int n;cin>>n;int x=0;
    for(int i=0;i<n;i++)
    {
        int no;
        cin>>no;
        x=x^no;
    }
    cout<<"Odd one out is "<<x;
}
