//Unique Number 3
//n numbers all repeated 3 times but 1
//find that odd number
//linear time

#include <iostream>
using namespace std;
int main()
{
    int bit[64]={0}; //to store all the bits of input number
    int j=0;
    int n;     cin>>n;
    int no;    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>no;
        j=0;
        while(no>0)
        {
            int last_bit=no&1;
            bit[j]+=last_bit;
            j++;
            no=no>>1;
        }
    }
    int s=0;
    for(int k=0;k<j;k++)
    {
        bit[k]=bit[k]%3;
        s=s+(bit[k]<<k);
    }
    cout<<s<<endl;
}





