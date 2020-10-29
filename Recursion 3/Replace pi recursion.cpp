//do in inplace without taking any extra array
#include <iostream>
#include <string>
using namespace std;

void replace_pi(char *a,int i)
{
   //base case
   if(a[i]=='\0' || a[i+1]='\0')
      return;

   //look for pi at the current location
   if(a[i]=='p' & a[i+1]=='i')
         {
            //shifting followed by replacement with 3.14
            //shifting should be done in the right to left order
            int j=i+2;
            //take j to end of array
            while(a[j]!='\0')
               j++;

            while(j>=i+2)
               {
                  a[j+2]=a[j];
                  j--;
               }

               //replacement
               a[i]="3";
               a[i+1]=".";
               a[i+2]="1";
               a[i+3]="4";

               //recursive call
               replace_pi(a,i+4);
         }
      else
      {
         //goto next position
         replace_pi(a,i+1);
      }
}

int main()
{
   char a[];
   cin>>a;
   n=strlen(a);
}
