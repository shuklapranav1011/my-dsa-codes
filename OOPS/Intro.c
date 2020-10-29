#include <iostream>
using namespace std;

class Car{
   //By default all data members are private
   public:
   int price;
   int model_no;
   char name[20]
};

int main()
{
   //object
   Car c;

   //Data Members
   c.price=10;
   c.model_no=1011;
   c.name='BMW\0';
   cout<<c.name<<endl;

   sizeof(c);     //28
   sizeof(Car); //28

   //At the present moment only memory occupied is by c and not class car.
   return 0;
}
