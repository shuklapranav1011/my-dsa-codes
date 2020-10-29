#include <iostream>
#include <strings.h>
using namespace std;

int strtoint(char *a, int n)
{
   int digit=a[strlen(a)-1] -'0';
   int small_ans= strtoint(a,strlen(a)-1);
   return (small_ans*10)+digit;
}

int main()
{
   char a[]="1234";
   strtoint(a,strlen(a));
}
