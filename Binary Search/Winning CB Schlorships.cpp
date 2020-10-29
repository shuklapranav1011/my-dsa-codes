 #include <iostream>
 #include <algorithm>
 using namespace std;

 bool can_get(int n,int m,int x,int y,int stud_g)
 {
     int coup_req=stud_g*x;
     int tot_coup=m+((n-stud_g)*y);
     if(coup_req<=tot_coup)
        return true;
     return false;
 }

 int main()
 {
     int n,m,x,y;
      cin>>n>>m>>x>>y;
     int beg=0;
     int last=n;
     int ans;
     while(beg<=last)
     { int mid=(beg+last)/2;
         if(can_get(n,m,x,y,mid)==true)
         {
             ans=mid;
             beg=mid+1;
         }
         else
            last=mid-1;
     }
     cout<<ans;
 }
