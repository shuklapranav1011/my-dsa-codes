/*
Why do we need copy constructor?

Our default copy constructor provided by the compiler implements shallow copy wherein the elements are copied one by one. 
During dynamic memory allocation,
if shallow copy in done, adresses are copied and values are copied in the same members...new memory is not created therefore data is lost.

Therefore to copy contents during synamic memory allocations also, we need to implement deep copy which is done by user-defined deep copy constructor.
*/


// #include <bits/stdc++.h>
// using namespace std;

// class Test{
//     private:
//     int *p;
    
//     public:
//     Test (int x){
//         p = new int(x);
//     }
    
//     void set(int x){
//         *p = x;
//     }

//     void print(){
//         cout<<*p <<" ";
//     }
// };

// int main(){
//     Test t1(10);
    
//     Test t2(t1);  //shallow copy
    
//     t2.set(20);

//     t1.print();
//     t2.print();
// }



//Implementing Deep Copy


#include <bits/stdc++.h>
using namespace std;

class Test{
    private:
    int *p;
    
    public:
    Test (int x){
        p = new int(x);
    }
    
    //Deep Copy COnstructor

    Test(Test &t){
        int temp = *(t.p);
        p = new int(temp);
    }
    /*
        Test(Test &t){...}
        Here,
        we pass Test &t i.e. as a reference beacuse if we pass by value, this copy constructor call will call another copy constructor call. This means the copy constructor would call itself to make copy and the program will go into a non-terminating loop;
    */

    void set(int x){
        *p = x;
    }

    void print(){
        cout<<*p <<" ";
    }
};

int main(){
    Test t1(10);
    
    Test t2(t1);  //shallow copy
    
    t2.set(20);

    t1.print();
    t2.print();
}