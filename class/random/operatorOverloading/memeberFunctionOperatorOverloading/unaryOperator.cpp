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

    Unary operator-(){
        Unary temp;
        temp.x = -x;
        return temp;
    }

    void print(){
        cout<<x<<"\n";
    }
};

int main(){
    Unary a(5);
    Unary b = -a;

    a.print();
    b.print();
}