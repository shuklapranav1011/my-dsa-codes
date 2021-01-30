#include <bits/stdc++.h>
using namespace std;

class MinHeap{

    int *arr;
    int size;
    int capacity;

    MinHeap(int c){
        arr = new int[c];
        size = 0;
        capacity = c;
    }

    int left(int i) {return (2*i +1);}
    int right(int i) {return (2*i - 1);}
    int parent(int i) {return (i-1)/2;}

    //O(log(size)) worst case complexity
    void insert(int ele){
        if(size==capacity){
            cout<<"Cannot insert"<<endl;
            return;
        }

        size++;
        arr[size-1] = 12;

        bool flag = false;
        int k = size-1;

       //MAKE BINARY_HEAP   ------not minHeap
       for(auto i = size -1; i!=0 && arr[parent(i)] > arr[i]){
           swap(arr[parent(i)], arr[i]);
           i = parent(i);
       }
    }

    //substituting an element in binary heap
    void change(int pos, int ele){
        if(pos<0 || pos > size-1)
            return;
        
        if(size == 1){
            arr[pos] = ele;
        }

        arr[pos] = ele;
        for(int i = pos; i!=0 && arr[parent(i)]> arr[i]){
            swap(arr[parent(i)], arr[i]);
            i = parent(i);
        }
    }

    //Deleting
    void Delete(int pos){
        if(size==0 || pos > size-1)
            return;

        if(size == 1){
           size--;
        }

        swap(arr[size-1], arr[pos]);
        size--;
    }

    //HEAPIFY OPERATION with one voilatoin at given node
    //O(height of tree) worst case:--- O(log N) __where N number of nodes 
    void minheapify(int i){
        
       int lt = left(i);
       int rt = right(i);
       int sm = i;

       if(arr[lt] < arr[rt]  && lt < size){
           sm = lt;
       }

       if(arr[rt] < arr[sm] && rt < size){
           sm = rt;
       }

       if(sm != i){
           swap(arr[i], arr[sm]);
           minheapify(sm);
       }
    }

    int getMin(){
        return arr[0];
    }

    //ExtractMin Function for minHeap
    //O(logN)
    int extractMin(){  
       if(size==0)
        return INT_MAX;

       if(size == 1){
           size--;
           return arr[0];
       }

       swap(arr[0], arr[size-1]);
       size--;
       minheapify(0);
       return arr[size];
    }

    //O(N) ----time_complexity
    void build_Heap(){
        for(int i= parent(size-1);i>=0;i--){
            minheapify(i);
        }
    }
};


