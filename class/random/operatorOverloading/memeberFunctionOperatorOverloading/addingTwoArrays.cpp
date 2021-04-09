#include <bits/stdc++.h>
using namespace std;

class Array{
    private:
    int n;
    int *a;

    public:
    Array();
    Array(int n);
    void print();
    Array operator+(Array &);
    ~Array(){
        delete []a;
        cout<<"destroyed\n";
    }    
};

Array:: Array(){
    int n = 1;
    a = new int[n];
    a[0] = 0;
}

Array:: Array(int n){
    this->n = n;
    a = new int[this->n];
    cout<<"Enter array \n";
    for(int i = 0; i<this->n; i++){
        cin>>a[i];
    }
    cout<<"\n";
}

void Array:: print(){
    for(int i = 0; i<n ;i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}

Array Array::operator+(Array &A){
    Array temp;
    temp.n = this->n;
    for(int i=0;i<temp.n;i++){
        temp.a[i] = this->a[i] + A.a[i];
    }

    return temp;
}

int main(){
    int size;
    cin>>size;

    Array A(size),B(size);
    Array C = A+B;

    A.print();
    B.print();
    C.print();
}