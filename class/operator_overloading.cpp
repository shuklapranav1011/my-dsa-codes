#include <bits/stdc++.h>
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;

class complexNo
{
    int real, img;

public:
    complexNo()
    {
        real = 2;
        img = 3;
    }

    void show_data()
    {
        cout << "Complex no = " << real << " + i " << img << "\n";
    }

    complexNo operator++() //pre-increment  ++x
    {
        complexNo temp;
        real++;
        img++;
        temp.real = real;
        temp.img = img;
        return temp;
    }

    complexNo operator++(int) //post-increment x++
    {
        complexNo temp;
        temp.real = real;
        temp.img = img;
        real++;
        img++;
        return temp;
    }

    complexNo operator+(complexNo c) /// member function
    {
        complexNo temp;
        temp.real = real + c.real;
        temp.img = img + c.img;
        return temp;
    }

    friend complexNo operator+(complexNo c, complexNo d){} //friend function is defined outside the class.
};

int main()
{
    IOS;
    complexNo c1, c2;
    c1.show_data();
    c1 = ++c2; //c2.operator() //pre-increment called
    c2.show_data();
    c1.show_data();

    cout << "--------\n";
    c1 = c2++;
    c2.show_data();
    c1.show_data();

    return 0;
}

/*
member function ko koi object hi call kr skta hai.    c2.add(c1);                              friend function ko koi object nai call krega....seedhe call ho jayega.   add(c2,c1);
friend function se ek argument kam pass hoga member function k case me.

Need for friend function.????

c1+c2 ko member aur friend dono se execute krva skte hai....no problem. But for example

Eg...
3 + c2 krna hai. ab?? member function nai lga skte kynki member m to 1st object hona chiye...
call krte time 3.add(c2) hota....to ERROR aata...
but using friend function...  add(int a, complex c)


Eg...
c2 + 3 ko friend aur member dono se kr skte hain.  c2.add(3).   add(obj c2, int a)



....... in member function obj2 = obj1 + 10; is okay but obj2 = 10 + obj1; !!! is not okay ...............  in friend function both are okay...

*/