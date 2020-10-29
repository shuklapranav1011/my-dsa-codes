#include <iostream>
#include <cstring>
using namespace std;
//access specifiers - public,private and protected
class Car{
   //By default all data members are private


private:
   int price;
public:
   int model_no;
   char name[20];

//constructor to overide default
Car()
{
   cout<<"Inside Class Constructor";
}

//parametrized constructor
Car(float p,int m, char*n)
{
   price=p;
   model_no=m;
   strcpy(name,n);
}

//copy Constructor
Car(Car &x)
{
   cout<<"Copy Constructor"<<" ";
   price=x.price;
   model_no=x.model_no;
   strcpy(name,x.name);
}

//getter method
   float get_price()
   {
      return price;
   }

//setter method
   void set_price(int p)
   {
      int msp=111;
      if(p>0)
         price=p;
         else
            price=msp;
   }

//function
   void print()
   {
      cout<<price;
   }
};

int main()
{
   //object
   //makes a call to default constructor present in the class
   Car d(222,333,"Audi"); //using parametrized constructor
   Car e(d);//copy constructor
   //another way of calling copy constructor
   Car f=d;  //makes a call to the copy constructor

   //Data Members
   c.model_no=1011;
   c.name[0]='B';
   c.name[1]='\0';
   sizeof(c);     //28
   sizeof(Car); //28

   d.print();
   //At the present moment only memory occupied is by c and not class car.
   return 0;
}
