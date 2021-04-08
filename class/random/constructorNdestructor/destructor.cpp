/*
Only one destructor in a class although class can have multiple constructors;

*/

#include <bits/stdc++.h>
using namespace std;

class Test{
    private:
    int t;

    public:
    Test():t(0){
        cout<<t<<" Default Constructor called \n";
    }
    
    Test(int x):t(x){
        cout<<x<<" Parametrized contructor called \n";
    }

    ~Test(){
        cout<<t<<" Contructor Destroyed \n";
    }
};

int main(){
    cout<<endl;
    Test t1;
    {
        Test t2(10);
        {
            Test t3(30);
        }
    }
    return 0;
}