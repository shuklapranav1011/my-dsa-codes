//Ladder Problem
/*
*/

//for 3 jumps maximum
int ladder(int n)
{
      if(n==0)
         return 1;
      if(n<0)
         return 0;
     return  f(n-1)+f(n-2)+f(n-3);
}

//for k jumps maximum
int ladder(int n,int k)
{
   if(n==0)
      return 1;
   if(n<1)
      return 0;
      int ans=0;
   for(int i=1;i<=k;i++)
   {
      ans=ans+(ladder(n-i),k);
   }
   return ans;
}

int main()
{
   int n;
   cin>>n;

}
