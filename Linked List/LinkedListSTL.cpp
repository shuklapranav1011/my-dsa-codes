#include <iostream>
#include <forward_list>
using namespace std;

int main()
{
   forward_list<int> first; //empty linked list
   forward_list<int> second (3,77); //3 seventy sevens
   forward_list<int> third (second.begin(),second.end());

   forward_list<int> fifth={3,77};  //contains 3 and 77
   for(auto x:second)
      cout<<x<<endl;

   cout<<endl;

   for(auto x:fifth)
      cout<<x<<endl;

   //input linked
   forward_list<int> a;
   int k;
   cin>>k;
   while(k!=-1)
   {
      a.push_front(k);
      cin>>k;
   }

   cout<<endl;

    for(auto x:a)
      cout<<x<<endl;

   a.pop_front();

     cout<<endl;

    for(auto x:a)
      cout<<x<<endl;

   a.sort();
   fifth.sort();
   //merge two sorted linked list
   a.merge(fifth);


   cout<<endl;

    for(auto x:a)
      cout<<x<<endl;

   //insert_after function
   //returns iterator to the newly inserted element position

   //inserting at head
   //push_front
   auto it=a.insert_after(a.before_begin(),999);

   //in middle
   it=a.insert_after(a.begin(),{999,918,917}); //adds 2 99s after a.begin


 cout<<endl;

    for(auto x:a)
      cout<<x<<endl;


}
