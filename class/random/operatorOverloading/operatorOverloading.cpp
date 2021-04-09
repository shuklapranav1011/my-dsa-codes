#include <bits/stdc++.h>
using namespace std;

class Complex{

    int a,b;

    public:
    Complex():a(0),b(0){}

    Complex(int a,int b){
        this->a = a;
        this->b = b;
    }

//operator overloading
    Complex operator+(Complex c){
        Complex res;
        res.a = this->a + c.a;
        res.b = this->b + c.b;
        return res;
    }

    void print(){
        cout<<a<<" + i "<<b <<"\n";
    }
};

int main(){
    cout<<endl;
    Complex x(10,20);
    x.print();

    Complex y(20,30);
    y.print();

    Complex z = x+y;
    z.print();
    cout<<endl;
}