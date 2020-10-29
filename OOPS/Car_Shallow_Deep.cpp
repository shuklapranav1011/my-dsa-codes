
#include <iostream>
#include <cstring>
using namespace std;

class Car{

private:
   int price;
public:
   int model_no;
   char *name;
   const int msp; //this is a read-only variable


      Car() : msp(99) //initialization list
      {
         name=NULL;
      }
     Car(float p,int m, char*n,int minprice=99) : price(p),msp(minprice)
      {
         price=p;
         model_no=m;
        //we need to allocate memory first
        name=new char[strlen(n)+1];
        strcpy(name,n);
      }
      //Deep Copy Constructor
      Car(Car &x)
      {
         cout<<"Copy Constructor"<<" ";
         price=x.price;
         model_no=x.model_no;
         //now we cannot do name=X.name, shallow copy;
         name=new char[strlen(x.name)+1];
         strcpy(name,x.name);
         }
      //Deep Copy Assignment operator
      void operator=(Car &x)
      {
         price=X.price;
         model_no=x.model_no;
         name=new char[strlen(x.name)+1];
         strcpy(name,x.name);
      }
      //Destructor
      ~Car()
      {
         cout<<"Inside Destructor of car"<<name<<endl;
         if(name=NULL)
            delete [] name;
      }
      void set_price(int p)
      {
         int msp=111;
         if(p>0)
            price=p;
         else
            price=msp;
      }
         void print()
         {
            cout<<"Price"<<price<<endl;
            cout<<"name"<<name<<endl;
         }

};


int main()
{
   Car c(100,200,"BMW");
   Car d(c); //copy constructor

   d.set_price(400);
   c.name[0]='A';

   //Shallow Copy Problem
   //No copy constructor defined
   //the value of d.name also changes when c.name is changed and vice versa.
   //This is because the memory location of name is shared between c and d

   //Deep Copy

   Car f;
   f=d; //Copy constructor does not get called;
   //instead we call assignment operator

   c.print();
   d.print();

   Car *e= new Car(10,20,"Ferrari");

   (*e).print();

   //or

   e->print();

   delete e; //another way to delete objects(dynamically created)

}












