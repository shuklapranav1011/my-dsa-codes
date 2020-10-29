//cars given at certain distance from origin
//given car name, x and y co-ordinates

//using user defined class

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class car{

    private:
    int x,y;
    string name;

    public:
    car()
    {}
    car(string name,int x,int y)
    {
        this->x=x;
        this->y=y;
        this->name=name;
    }
    int dist()
    {
        return (x*x+y*y);
    }
};

bool compare(car a,car b)
{
    if(a.dist()==b.dist())
        return a.name.length()<b.name.length();
    return a.dist()<b.dist();
}

int main()
{
    int n;cin>>n;
    vector <car> v;
    for(int i=0;i<n;i++)
    {
        int x,y;
        string name;
        cin>>name>>x>>y;
        car obj(name,x,y);
        v.push_back(obj);
    }
    sort(v.begin(),v.end(),compare);

    for(int i=0;i<n;i++)
    {
       cout<<v[i].name<<" "<<v[i].x<<" "<<v[i].y<<endl;
    }
}
