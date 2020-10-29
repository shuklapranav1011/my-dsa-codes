#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    priority_queue <int> maxHeap;
    priority_queue < int , vector<int> , greater<int> > minHeap; 

    int x;
    cin>>x;
    float median=x;
    maxHeap.push(x);
    cout<<"Median is = "<<median<<endl;
    cin>>x;
    while(x!=-1)
    {
        if(maxHeap.size()>minHeap.size())
        {
            if(x<median)
            {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(x);
            }
            else
            {
                maxHeap.push(x);
            }
            median = (maxHeap.top() + minHeap.top())/2.0;
        }
        else if(maxHeap.size()==minHeap.size())
        {
             if(x<median)
            {
                maxHeap.push(x);
                median = maxHeap.top();
            }
            else
            {
                minHeap.push(x);
                median = minHeap.top();
            }
        }
        else
        {
            if(x>median)
            {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(x);
            }
            else
            {
                minHeap.push(x);
            }
            median = (maxHeap.top() + minHeap.top())/2.0;
        }
    }
}