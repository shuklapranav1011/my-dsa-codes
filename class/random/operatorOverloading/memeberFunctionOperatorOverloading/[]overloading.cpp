/*
    THe overloaded operator []()  must be a non-static member of a class
*/

#include <bits/stdc++.h>
using namespace std;

class Array{
    int arr[10];

    public:
    Array();
    void getData();
    void print();
    int operator[](int i);
};

Array :: Array(){
    for(int i = 0;i<10;i++){
        arr[i] = 0;
    }
}

void Array::getData(){
    cout<<"\nEnter array\n";
    for(int i=0; i<10;i++){
        cin>>arr[i];
    }
}

void Array::print(){
    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

int Array::operator[](int i){
    return arr[i]*2;
}


int main(){
    Array A;
    A.getData();
    A.print();

    int x[10];
    for(int i = 0; i<10; i++){
        x[i] = A[i];
    }
   
   for(int i = 0;i < 10;i++){
       cout<<x[i]<<" ";
   }
   cout<<"\n";
}