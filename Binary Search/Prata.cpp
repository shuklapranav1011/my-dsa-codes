 #include <iostream>
 #include <algorithm>
 using namespace std;

 bool can_make(int r[],int p,int l,int time)
 { int pmade=0;
     for(int j=0;j<l;j++)
     {
     int s=0;
     for(int i=0;i<=time;i+=r[j]*++s)
     {
     }
     pmade=pmade+(s-1);
     if(pmade>=p)
        return true;
     }
    return false;
 }
 int main()
 {
     int p;
     cin>>p;//prata ordered
     int l;
     cin>>l;//number of cooks
     int ranks[l];
     for(int i=0;i<l;i++)
        cin>>ranks[i];
     sort(ranks,ranks+l);

     //assume a limit for time
     int beg=0;
     int last=(p*(p+1))/2; //Time taken if only the fastest cook is working to make

     int ans;
cout<<"Prata in 12 min"<<can_make(ranks,p,l,12)<<endl;
     while(beg<=last)
     {
         int mid=(beg+last)/2;
         if(can_make(ranks,p,l,mid)==true)
         {   cout<<mid<<" is possible"<<endl;
             ans=mid;
             last=mid-1;
         }
         else
         {cout<<mid<<" is not possible"<<endl;
           beg=mid+1;
         }
     }
     cout<<ans<<endl;
 }
