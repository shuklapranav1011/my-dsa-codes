class prime_sieve{
vector<int> prime_sieve(int *p,int n)
{
   p[0]=p[1]=0;
   p[2]=1;
   for(int i=3;i<=n;i+=2)
    {
      p[i]=1;
   for(int i=3;i<=n;i+=2)
   {
      if(p[i]==1)
      for(int j=i*i;j<=n;j+=i)
         p[j]=0;
   }
    }
   vector <int> primes;
   primes.push_back(2);
   for(int i=3;i<=n;i+=2)
      if(p[i]==1)
      primes.pushback(a[i]);

   return primes;
}
}
