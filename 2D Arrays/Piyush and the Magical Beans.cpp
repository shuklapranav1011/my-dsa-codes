/*
Piyush and the Magic Beans

Piyush enters a park with strength S. The park is filled with some obstacles denoted by '.' ,
some magical beans denoted by '*' and some blockades denoted as '#'.
For every '.' he encounters his strength decreases by 2
For every '*' he encounters his strength increases by 5
He can only walk from left to right and he does this for every row.
If he encounters a blockade '#' , he cannot go further in his current row and simply jumps to he start of a new line
without losing any strength.
He requires 1 energy for each step;
If his energy is less than K then he cannot complete the path.

Assume- Piyush can shift form last of one row to the start of the other row without losing any energy.

His escape is sucessful if he is able to return home with atleast K strength left.

Print if he can escape and amount of strength left.

Example :

. . * .
. # . .
* * . .
. # * *

K=5 and S=20

Output:
Yes
13
*/

#include <iostream>
using namespace std;
int main()
{

    int m,n,k,s;
    cout<<"Enter Limits"<<endl;
    cin>>m>>n;
    cout<<"Enter Minimum energy and Initial Energy";
    cin>>k>>s;
    char a[m][n];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }


/*  while(i<m)
    {
        if(k<s && a[i][j]=='.')
        {
            s=s-2;
            j++;
            if(j==n-1)
            {
                i++;
                j=0;
                continue;
            }
            else
            {
                s=s-1;
            }
        }

        if(k<s && a[i][j]=='*')
        {
            s=s+5;
            j++;
            if(j==n-1)
            {
                i++;
                j=0;
                continue;
            }
            else
            {
                s=s-1;
            }
        }

        if(k<s && a[i][j]=='#')
        {
            j=0;
            i++;
        }
    }
    if(i>m-1)
    {
        cout<<"Yes \n"<<s;
    }
    else
    {
        cout<<"No";
    }

}
*/
bool flag=true;
for(int i=0;i<m;i++)
{
    for(int j=0;j<n;j++)
    {

        if(k>=s)
        {
            flag=false;
            break;
        }

        else
        {
            if(a[i][j]=='.')
                s=s-2;
            else if(a[i][j]=='#')
                s=s+5;
            else
                break;

            if(j!=n-1)
                s--;
        }
    }

    if(flag==false)
        break;
}

if(flag==true)
{
    cout<<"Yes "<<s;
}
}














































