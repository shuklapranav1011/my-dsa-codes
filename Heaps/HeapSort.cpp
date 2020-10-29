//Sorting Algorithm
//Inplace

//................................//
//Make max_heap
//remove largest ele ----shrink size of heap
//remove largest element
//make heap
//remove largest ele ----shrink size of heap
//make heap
//................................//

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

 void heapify(vector <int> v,int idx,int n)
    {
        int left=2*idx;
        int right=left+1;

        int min_idx=idx;
        int last=n;

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
            heapify(v,min_idx,n);
        }
    }

void buildHeap(vector<int> v)
{
    for(int i=v.size()-1/2;i>=1;i--)
    {
        heapify(v,i,v.size());
    }
}
  
void heapsort(vector <int> &a)
{
    buildHeap(a);
    int n=a.size();

    while(n>1)
    {
        swap(a[1],a[n-1]);
        n--;
        heapify(a,1,n); //so that heapify runs on array taht we are maintaining
    }
}
