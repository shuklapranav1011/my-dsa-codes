#include <iostream>
#include <vector>
using namespace std;
void prime_factors(int n)
{
    //output prime factors till of n
    vector < pair<int,int> >factors;
    int i=0;
    int cnt;
    for(i=2;i*i<=n;i++) //we use i*i <=n instead of i<=sqrt(i).  It is essentially the same
    {

        if(n%i==0)
        {
           cnt=0;
           while(n%i==0)
            {
                cnt++;
                n=n/i;
            }
             factors.push_back(make_pair(i,cnt));
        }
    }
    if(n!=1)
        factors.push_back(make_pair(n,1));

    for(i=0;i<factors.size();i++)
        cout<<factors[i].first<<" to power "<<factors[i].second<<endl;
}
int main()
{
    int n;
    cin>>n;
    prime_factors(n);
}
