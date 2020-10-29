
#include<bits/stdc++.h>
#include<math.h>
using namespace std;

#define pi 3.141593

class xy{
    public:
        float x;
        float y;
};

float dist(xy p1, xy p2)
{
    float dis=sqrt( pow(p1.x-p2.x,2) + pow(p1.y-p2.y,2) );
    return dis;
}

int main(){

    int rad;
    float dia[4]={0};
    cin>>rad>>dia[1]>>dia[2]>>dia[3];
    float deg[4];
    for(int i=0;i<4;i++)
      cin>>deg[i];
    float vel[4];
    for(int i=0;i<4;i++)
      cin>>vel[i];
    int rond[4];
    for(int i= 0; i< 4; i++)
        cin>>rond[i];
    int time;
    cin>>time;
    for(int i= 0;i<4;i++)
    {
       if(rond[i]==1)
            deg[i]+=time*vel[i];
      else if(rond[i]==0)
            deg[i]-=time*vel[i];
        deg[i] *= (pi/180); //converting to radians
    }
    xy p[4];
    for(int i= 0; i< 4; i++)
      {
        p[i].x= rad*cos(deg[i]) + dia[i];  //rcosQ + radi  = x component from geometry
        p[i].y= rad*sin(deg[i]); //rsinQ = y comppnent from geometry
      }
    float length= 0;
    for(int i= 0; i< 3; i++){
        length+= dist(p[i], p[i+1]);
    }
   int k=round(length);
   cout<<k;
   }
