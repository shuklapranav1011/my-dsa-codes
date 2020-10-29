#include <iostream>
#include <queue>
using namespace std;
 
class Person
{
    public:
    string n; int age;
    Person(string na,int a)
    {
        n=na;
        age=a;
    }
};

class PersonCompare{
    public:
    bool operator()(Person A, Person B)
    {
        return A.age<B.age;
    }
};

int main()
{
    int n;
    cin>>n;
    priority_queue <Person , vector <Person> , PersonCompare> pq; // we have passed a class containing a functor
    for(int i=0;i<n;i++)
    {
        string name;
        int age;
        cin>>name>>age;
        Person p (name,age);
        Person p(name,age);
        pq.push(p);
    }
}