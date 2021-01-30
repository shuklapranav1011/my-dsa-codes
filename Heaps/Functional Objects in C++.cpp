#include <iostream>
#include <queue>
using namespace std;


class Fun
{
    public:
        void operator()(string s){
            cout<<"Having fun inside operator fun"<<s;
        }
};


int main()
{
    priority_queue <int> pq;
    Fun f;
   // f(); // overloaded () operator = function call where c is an object
    f("C++"); 

    /*This is called Functor*/
    
    //an overloaded object that can be called as a function
}