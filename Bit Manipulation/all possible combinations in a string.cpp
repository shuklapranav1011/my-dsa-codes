//a string "abc"
//all possible combinations are "",a,b,c,ab,bc,ca,abc
//find all possible combinations in a given string

#include <string>
#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;

//Approach 1 NOOB - generate truth table and then print accordingly
/*
int main
{
    char a[1000];
    cin>>a;

   //generating truth table

    int row=pow(2,strlen(a));
    int col=strlen(a);
    int truth_table[row][col];
    int row_val=0;int j=0;

    for(int i=0;i<row;i++)
    {
        int j=0;

       if(i==0)
        {   while(j<col)
                {
                    truth_table[i][j]=0;
                    j++;
                }
        }
       else
       {   int x=i;
           while(x>0)
           {
               int last_bit=x&1;
               truth_table[i][j]=last_bit;
               j++;
               x=x>>1;
               if(x==0&&j<col)
               {
                   while(j<col)
                    {
                        truth_table[i][j]=0;
                        j++;
                    }
               }
           }
       }
    }

    cout<<"all combinations are:"<<endl;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(truth_table[i][j])
            cout<<a[j];
        }
        cout<<endl;
    }
}

*/

void filter(int n,char a[])
{
    int j=0;
    while(n>0)
    {
        int last_bit=n&1;
        if(last_bit)
            cout<<a[j];
        j++;
        n=n>>1;
    }
}

int main()
{
    char a[1000];
    cin>>a;

    for(int i=0;i<(1<<strlen(a));i++)
    {
        filter(i,a);
        cout<<endl;
    }
}



































