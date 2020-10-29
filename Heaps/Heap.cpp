//Heaps mainly helps us with solving the problems of maximum or minimum of N elements

/*
-->Ex- 10000 students appeared for a test.
Give top 10.

-->Using Algorithm (NlogN) elements we can get.
But we do not need to rank all the elements.
We need only max/min.

-->We can use heap for better complexity.

-->What is a heap?
1. Binary Tree
2. Complete Binary Tree Property(CBT)
3. Heap Order Property

-->Using Binary Tree as a method of insertion.
Insertion of an element in a heap using level order traversal, takes a lot
of time. This defeats the purpose of heap.

-->Using an array
We use complete bst property of a heap.

--> Parent                i 
    Children        2i          2i+1

--> Children         i
--> Parent           i/2


Worst Case Insertion -- O(log(N))
getMinimum -- O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Heap
{
    vector<int> v;
    bool minHeap;

    bool compare(int a, int b)
    {
        if(minHeap==true)
        return a<b;
        else
        return a>b;
    }

    void heapify(int idx)
    {
        int left=2*idx;
        int right=left+1;

        int min_idx=idx;

        if(left<=v.size()-1 && compare(v[left],v[idx]))
        {
            min_idx = left;
        }   

        if(right<=v.size()-1 && compare(v[right],v[idx]))
        {
            min_idx = right;
        }

        if(idx!=min_idx)
        {
            swap(v[idx],v[min_idx]);
            heapify(min_idx); 
        }
    } //this function makes a heap from a given node;

public:
    Heap(int default_size=10, bool type=true)
    {
        v.reserve(default_size);
        v.push_back(-1);
        minHeap = type;
    }

    void push (int d)//--O(logN)
    {
        //step 1 -- Entering Element

        v.push_back(d);
        
        //step 2 -- Comparison
        int idx=v.size()-1;
        int parent = idx/2;

        //Step 3 -- Swap
        /*
        keep pushing curr_node to the top till root node or curr_ele
        is greater than the element
        */

        while(idx > 1 && compare(v[idx], v[parent]))
        {
            swap(v[idx],v[parent]);
            idx=parent;
            parent=parent/2;
        }
    }

    void pop(vector<int> v) //--O(logN)
    {
        //Step 1 -- Swap
        swap(v[1],v[v.size()-1]);
        
        //remove element at last
        v.pop_back();

        //make heap again
        heapify(1);
    }
};

int main()
{
    //give base size, type of heap
}























