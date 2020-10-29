#include <iostream>
#include <queue>
#include <vector>
using namespace std;


/*
Given N ropes of sifferent sizes, we have to join the ropes
togrther.
Cost of joining 2 ropes of sizes a and b is (a+b).
Find the minimum cost of joining the all the ropes together
*/


int join_ropes(int *a,int n)
{
    //minHeap
    priority_queue < int, vector <int> , greater <int> > pq;
    for(int i=0;i<n;i++)
    {
        pq.push(a[i]);
    }

    int tot_cost=0;
    int curr_cost=pq.top();
    pq.pop();
    while(!pq.empty())
    {
        curr_cost+=pq.top();
        tot_cost+=curr_cost;
        pq.pop();
    }

    return tot_cost;
}


int main()
{
    int ropes[]={4,3,2,6};
    int n=4;

    cout<<join_ropes(ropes,n)<<endl;
}