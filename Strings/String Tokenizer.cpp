#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char s[100]="This is String Tokenizer";
    char *p=strtok(s," ");
    cout<<p<<endl;

    while(p!=NULL)
    {
        p=strtok(NULL," ");
        cout<<p<<endl;
    }
}
