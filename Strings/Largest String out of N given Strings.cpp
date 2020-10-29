#include <iostream>
#include <cstring>
using namespace std;

void largest_string()
{
    int n;
    cout<<"Enter number of string inputs";
    cin>>n;

    char curr_s[1000];
    char largest_s[1000]={};
    cin.get();
    for(int i=0;i<n;i++)
    {
        cin.getline(curr_s,1000);
        if(strlen(curr_s)>strlen(largest_s))
        {
            strcpy(largest_s,curr_s);
        }
    }
    cout<<largest_s;
}
