//find the minimum sum of digits to make a number n

#include <iostream>
using namespace std;
int reqDigits(int a)
{
   if(a%9==0)
      return (a/9);
   return (a/9) + 1;
}
 int main()
 {
    int cases;    cin>>cases;
    while(cases--)
    {
      int pr,pc;
      cin>>pc>>pr;
      pr=reqDigits(pr);
      pc=reqDigits(pc);
      if(pr<=pc)
         cout<<"1 "<<pr<<endl;
      else
         cout<<"0 "<<pc<<endl;
    }
 }
