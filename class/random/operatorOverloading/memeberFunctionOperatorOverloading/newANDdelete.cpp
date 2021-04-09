/*
--> NEW keyword overload syntex:    void* operator new(size_t size)

        --> return type should be void* returning pointer to the star of overloaded block of memory.
        
        --> size_t specifies the number of bytes of memory to be stored.

--> DELETE keyword overload syntax:  void operator delete(void*)


--> Both new and delete operators are automatically static so they do not have access to this pointer.


--> We can have more than one overloaded new and delete operators

--> Globally overloaded and locally overloaded.
Locally overlaoded new and delete operator work only when the class is called;
*/


#include <bits/stdc++.h>
using namespace std;

void * operator new(size_t size){
    cout<<"\noperator overloading new size "<< size << "\n";
    void *ptr = malloc(size);
    return ptr;
}

void operator delete(void* ptr){
    cout<<"\noverloaded delete called\n";
    free(ptr);
}

void operator delete [](void* ptr){
    cout<<"\nArray overloaded delete called\n";
    free(ptr);
}

int main(){
    int *a,*b;
    a = new int[40];
    b = new int[20];
    delete a;
    delete[] b;
}

