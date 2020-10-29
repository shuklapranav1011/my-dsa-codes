/*Given N, friends who want to go for a party on bikes.
Each guy can go as single, or as a couple. Find the number of ways in which N friends
can go to a party.*/

//one person goes alone and rest
int f(int n)
{
   if(n==0)
      return 1;
   if(n=1)
      return 1;
   if(n=2)
      return 2;
   return f(1)*f(n-1) + (n-1) * f(n-2);
}
