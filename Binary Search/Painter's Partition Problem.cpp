 #include <iostream>
 #include <algorithm>
 using namespace std;

 bool paint_time(int l[],int k,int n,int t)
 {
    int time_taken=0;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        time_taken+=l[i];
        if(time_taken>t)
        {
            time_taken=l[i];
            cnt++;
            if(cnt>k)
                return false;
        }
    }
    return true;
 }

 int main()
 {
     int k,n;
     cin>>k>>n;
     int len_b[n];
     for(int i=0;i<n;i++)
        cin>>len_b[i];
     sort(len_b,len_b+n);

     int beg=len_b[n-1];//length of largest board
     int last=0;
     for(int i=0;i<n;i++)
        last=last+len_b[i];
        //sare boards ek hi painter paint kre
     int ans;

     while(beg<=last)
     {
         int mid=(beg+last)/2;
         if(paint_time(len_b,k,n,mid)==true)
         {   cout<<mid<<" is possible"<<endl;
             ans=mid;
             last=mid-1;
         }
         else
         {
             cout<<mid<<" is not possible"<<endl;
             beg=mid+1;
         }
     }
     cout<<ans;
 }
