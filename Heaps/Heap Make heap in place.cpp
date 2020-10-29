#include <iostream>
#include <vector>
using namespace std;

 bool minHeap=false;

 bool compare(int a, int b)
    {
        if(minHeap==true)
        return a<b;
        else
        return a>b;
    }

 void heapify(vector <int> v,int idx)
    {
        int left=2*idx;
        int right=left+1;

        int min_idx=idx;
        int last=v.size()-1;

        if(left<=last && compare(v[left],v[idx]))
        {
            min_idx=right;
        }

        if(right<=last && compare(v[left],v[idx]))
        {
            min_idx=right;
        }

        if(min_idx != idx)
        {
            swap(v[idx],v[min_idx]);
            heapify(v,min_idx);
        }
    }

//Build Max Heap o(NlogN)
void makeHeap(vector<int> v)
{
    for(int i=2;i<v.size();i++)
    {
        int idx=i;
        int parent=i/2;
        while(idx>1 && v[idx]>v[parent])
        {
            swap(v[idx],v[parent]);
            idx=parent;
            parent=parent/2;
        }
    }
}

//Build Heap from Array Optimized
//O(n)
//bottom-up
void buildHeap(vector<int> v)
{
    for(int i=v.size()-1/2;i>=1;i--)
    {
        heapify(v,i);
    }
}

int main()
{
    vector <int> v={-1,10,20,5,6,1,8,9,4};
    //we have blocked the 0 element

   /*  makeHeap(v); //O(NlogN) */
    buildHeap(v); //O(N)
}