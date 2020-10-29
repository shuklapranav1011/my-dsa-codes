#include <iostream>
using namespace std;

int duplicate(int a[])
{   bool flag=true;
    int n=sizeof(a)-1; //because the size also includes the '\0' character at the end of the string
    int m=n/2;
    for(int i=0;i<m;i++)
    {
        if(a[i]!=a[n-i-1])
            flag=false;
    }
    if(flag==true)
        cout<<"Palindrome"<<endl;
    else
        cout<<"Not Palindrome"<<endl;
    }
