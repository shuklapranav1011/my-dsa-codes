#include<bits/stdc++.h>

using namespace std;

class Name{
    public:
    Name(){
        cout<<"John\n";
    }
    Name(string s){
        cout<<s<<"\n";
    }
};

class Fullname{
    private:
    Name first, last;
    public:
    Fullname():first("Pranav"),last("Shukla"){}

    // Fullname(){
    //     first = Name("Pranav");
    //     last = Name("Shukla");
    // }
};



int main(){
    Fullname a;
}


/*
//when we use initialization lists, our members are initialized only once unlike when we use normal initialization when all our members are first initialized with default contructor.
then parametrized contrustor.
*/