//STL for Heap

//push --> O(logN)
//pop --> O(logN)
//top --> O(1)
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n;
    cin>>n;
/*
    priority_queue <int> pq;
    //this priority queue is a max heap
*/

    priority_queue <int, vector <int> , greater <int> > pq;
//this is for minHeap

    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        pq.push(x);
    }

    while(!pq.empty())
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }

} // main function