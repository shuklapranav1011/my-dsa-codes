#include <bits/stdc++.h>
using namespace std;

class Player{
    public:
    static int count;
    Player(){
        count++;
    }

    ~Player(){
        count--;
    }
};

int Player :: count = 0; 
/*
In c++, we need to define static members of a class this way outside the class.
*/

int main(){

    Player p1,p2; 
    //now two objects created -- count =2;
    cout << Player :: count << "\n";
    {
        Player p3;
        // -- count =3
        cout<< Player :: count<< "\n";
    }
    //count = 2;
    cout<< Player:: count <<"\n";
}

/*
    we can also access the static member by
    p1.count or p2.count 
    but it is recommended to acces the global variable by the class name;

    Player :: count
*/
