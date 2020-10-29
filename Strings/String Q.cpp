//String Question

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

bool compare()
{

}

int main()
{
    cout<<"Enter no. of Strings";//string entered shall follow the give rules.
    int n;
    cin>>n;

    cout<<"Enter position to sort by";
    int pos;
    cin>>pos;

    char **s=new char*[n];
    for(int i=0;i<n;i++)
    {
        s[i]=new char[100];
    }

    cout<<"Enter strings";
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }

    char *str=new char[n];
    for(int i=0;i<n;i++)
    {
        str[i]=s[pos-1][i];
    }


}




