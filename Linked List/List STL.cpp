#include <iostream>
#include <list>
#include <string>
using namespace std;

int main()
{
   list <int> l = {1,2,3,4,5,6,7,8,9};
   list <string> l2= {"apple, guava, graes, mangoes, banana"};
   l2.push_back("lichi");
   l2.sort();
   l2.reverse();
   l2.front();
   l2.pop_front();
   l2.pop_back();
   l2.pop_front("pomegranate");

   string f;
   cin>>f;
   le.remove(f); //remove removes by value

   //eraze one of more elements
   auto it=l2.begin();
   it++;
   it++;
   it++;

   l2.eraze(it); //eraze removes by position

   l2.insert(it,"FruitJuice");

   //using iterators
   for(auto it=l2.begin();it!=l2.end();it++)
   {
      cout<<*it<<"->";
   }
}
