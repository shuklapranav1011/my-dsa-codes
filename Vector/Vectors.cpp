#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Creating vector
    vector<int>a;
    vector<int>b(5,10); //5 integer elements with value 10
    vector<int>c(b.begin(),b.end()); //c is a vector containing elements of b vector
    //vector<int>d{1,2,3,4};

    //moving through vectors
    for(int i=0;i<c.size();i++)
        cout<<c[i]<<" ";
    cout<<endl;

//    for(auto it=b.begin();it!=b.end();it++)
  //      cout<<(*it)<<" ";
    //cout<<endl;

    for(int x:c)
        cout<<x<<" ";
    cout<<endl;

    //pushback

    vector<int>d;
    int n;;cin>>n;
    for(int i=0;i<n;i++)
    {
        int no;cin>>no;
        d.push_back(no);
    }

    cout<<v.capacity()<<endl;
    //pushback doubles the size of vector with every element the vector increses its size.
}
