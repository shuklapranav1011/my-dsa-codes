#include <iostream>

using namespace std;

namespace ns1{
    int x = 100;
    int value(){
        return x;
    }
}

namespace ns2{
    int x = 200;
    int value(){
        return x;
    }
}

void myFunc(string str = "China"){
    cout<<str;
}


void swap(int &a, int &b){
    int m;
    
    m = a;
    a = b;
    b = m;
}

int main(){
 
    cout<<ns1::value()<<endl;
    cout<<ns2::value()<<endl;

    return 0;
}