#include<bits/stdc++.h>
using namespace std;

#define M 1000000007

int largestRectangleArea(vector<int>& h) {

        if(h.empty()){
            return 0;
        }

        stack<int> s;

        s.push(0);
        int areaMax= h[0];

        int n= h.size();

        for(int i= 1; i < n; i++){

            int tp= s.top();

            if(h[i] >= h[tp]){
                s.push(i);
            }
            else{
                while(h[i] < h[tp] && !s.empty()){

                    s.pop();

                    if(s.empty()){
                        int area= h[tp]*(i);
                        areaMax= max(areaMax, area);
                    }
                    else{
                        int area= h[tp]*(i - s.top() - 1);
                        areaMax= max(areaMax, area);
                        tp= s.top();
                    }
                }
                s.push(i);
            }

        }

        int i= n;
        while(!s.empty()){
            int tp= s.top();
            s.pop();

                    if(s.empty()){
                        int area= h[tp]*(i);
                        areaMax= max(areaMax, area);
                    }
                    else{
                        int area= h[tp]*(i - s.top() - 1);
                        areaMax= max(areaMax, area);
                        tp= s.top();
                    }
        }

        return areaMax;
}

int main(){
    //freopen("input.txt", "r", stdin);

    int n, b, h;
    cin>>n>>b>>h;

    int totalArea= 0;
    vector<int> lengths;
    for(int i= 0; i< n; i++){
        int x;
        cin>>x;
        totalArea += x;
        lengths.push_back(x);
    }

    int area= largestRectangleArea(lengths);

    int ans= ((totalArea-area)*b*h) % M;

    cout<<ans;

    return 0;
}
