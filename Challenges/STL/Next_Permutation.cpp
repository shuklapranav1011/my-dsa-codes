#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int T; cin>>T;
    int N;

    while(T!=0)
    {
        cin>>N;
        int Arr[N];
    for(int i=0;i<N;i++)
    {
        cin>>Arr[i];
    }
    next_permutation(Arr,Arr+N);
    for(int i=0;i<N;i++)
    {
        cout<<Arr[i]<<" ";
    }
        T--;
        cout<<endl;
    }
}

