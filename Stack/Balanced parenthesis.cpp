#include <iostream>
#include <stack>
using namespace std;

bool isValidExp(char *ch)
{
   stack<int> s;
   for(int i=0;ch[i]!='\0';i++)
   {
      char x=ch[i];
      if(x=='(')
            s.push(x);
      else if(x==')')
         if(s.empty()||s.top()!='(')
               return false;
   }
   return s.empty();
}

int main()
{
   char ch[100]="(a+b*(c-d))";;
}
