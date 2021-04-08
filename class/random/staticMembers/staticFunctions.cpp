/*  
Static Funtions can access ONLY static data.

Non-static functions have access to static function as well as static variables...
Although it is NOT RECOMMENDED to change a static variable using a non-static function.

We should always define Static Functions to change the Static Variables and then use these static functions inside Non-static Functions if needed.
*/

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

    static int getCount(){
        return count;
    }
};

int Player :: count = 0; 

int main(){

    Player p1,p2; 
   
    cout << Player :: getCount() << "\n";
    {
        Player p3;

        cout<< Player :: getCount()<< "\n";
    }

    cout<< Player:: getCount() <<"\n";
}
