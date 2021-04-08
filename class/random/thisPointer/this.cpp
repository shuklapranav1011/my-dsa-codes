/*
 --> this pointer refers to the object on which we are currently working on.

 --> this pointer is a constant pointer and if we try to change this pointer we will get compiler error.

Advantages: 
    --> Making parameter names more meaningful
    --> Object Chaning

*/

#include <bits/stdc++.h>
using namespace std;

class Test{
    private:
    int x, y;

    public:
    Test():x(0),y(0){}

    Test(int x, int y){
        this->x = x;
        this->y = y;  
    }


    //working on the same object --- Object Chaning

    Test& setX(int x){
        this->x = x;
        return *this; 
    }

    Test& setY(int y){
        this->y = y;
        return *this;
    }

    void print(){
        cout<<x<<"  "<<y<<"\n";
    }
};

int main(){
    Test t1;
    t1.print();

    (t1.setX(10)).setY(20);
    t1.print();    
}
