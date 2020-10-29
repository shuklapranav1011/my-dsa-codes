#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

string txt[101]={"zero","one","two","three","four","five","six","seven","eight","nine","ten",
   "eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty","twentyone","twentytwo",
   "twentythree", "twentyfour" ,"twentyfive","twentysix","twentyseven","twentyeight","twentynine" ,"thirty","thirtyone","thirtytwo","thirtythree","thirtyfour","thirtyfive",
    "thirtysix", "thirtyseven", "thirtyeight","thirtynine","forty", "fortyone","fortytwo","fortythree","fortyfour", "fortyfive","fortysix","fortyseven", "fortyeight","fortynine",
    "fifty", "fiftyone", "fiftytwo", "fiftythree", "fiftyfour", "fiftyfive", "fiftysix", "fiftyseven", "fiftyeight", "fiftynine", "sixty", "sixtyone", "sixtytwo","sixtythree",
    "sixtyfour", "sixtyfive", "sixtysix", "sixtyseven", "sixtyeight", "sixtynine", "seventy", "seventyone", "seventytwo", "seventythree", "seventyfour",
    "seventyfive", "seventysix", "seventyseven", "seventyeight", "seventynine", "eighty", "eightyone", "eightytwo", "eightythree", "eightyfour",
    "eightyfive", "eightysix", "eightyseven", "eightyeight", "eightynine", "ninety", "ninetyone", "ninetytwo", "ninetythree",
    "ninetyfour", "ninetyfive", "ninetysix", "nintyseven", "ninetyeight", "ninetynine", "hundred"};

    int freq[10]={0};

int unorderedpairforI(int curr, int *a,int beg,int last,int sumVowels)
{
   int c=0;
   while(beg<=last)
   {
      int mid=(beg+last)/2;
      int sum= curr+a[mid];
      if(sum<sumVowels)
         beg=beg+1;
      else if(sum>sumVowels)
         last=last-1;
      else if(sum==sumVowels)
      {
         c++;
         break;
      }
   }
   return c;
}
bool isVowel(char ch)
{
   if(ch=='a' || ch=='A' || ch=='e' || ch=='E' || ch=='i' || ch=='I' || ch=='o' || ch=='O' ||	ch=='u' || ch=='U')
      return true;
   return false;
}
int count_vowels(string s)
{
   int c=0;
    int n = s.length();
    char cs[n + 1];
    strcpy(cs, s.c_str());
    for(int i=0;cs[i]!='\0';i++)
            if(isVowel(cs[i])==true)
               c++;
   return c;
}
int main()
{
   int n;
   cin>>n;
   int a[n];
   for(int i=0;i<n;i++)
      cin>>a[i];
   string atxt[n];
   for(int i=0;i<n;i++)
      atxt[i]=txt[a[i]];
   int sumVowels=0;
   for(int i=0;i<n;i++)
      sumVowels+=count_vowels(atxt[i]);
   int totalPairs=0;
   sort(a,a+n);
   for(int i=0;i<n;i++)
   {
      int curr=a[i];
      freq[a[i]]++;
      if(freq[a[i]]>1)
         continue;
      int beg=i;
      int last=n-1;
      totalPairs+=unorderedpairforI(curr,a,beg,last,sumVowels);
   }
   cout<<txt[totalPairs];
}
