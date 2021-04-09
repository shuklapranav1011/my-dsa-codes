#include <bits/stdc++.h>
using namespace std;

class Unary{
    private:
    int x;

    public:
    Unary():x(0){}
    Unary(int x){
        this->x = x;
    }
    void print(){
        cout<<x<<"\n";
    }

    friend Unary operator-(Unary &);  //friend function declared;
};

Unary operator-(Unary &N){
    Unary y;
    y.x = -N.x;   //N.x = -N.x will make change sin the same object
    return y;
}

int main(){
    Unary a(5);
    Unary b = -a;

    a.print();
    b.print();
}