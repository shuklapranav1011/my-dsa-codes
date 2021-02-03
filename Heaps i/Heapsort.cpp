#include <bits/stdc++.h>
using namespace std;

int left(int i) {return 2*i+1;}
int right(int i) {return 2*i+2;}
int parent(int i) {return (i-1)/2;}

void maxheapify(vector<int> arr,int size, int i){
    
    int lt = left(i);
    int rt = right(i);
    int lg = i;

    if(arr[lt] > arr[lg] && lt<size){
        lg = lt;
    }

    if(arr[rt] > arr[lg] && rt<size){
        lg = rt;
    }

    if(lg!=i){
        swap(arr[lg], arr[i]);
        maxheapify(arr, size, lg);
    }
}

void heapSort(vector<int> arr, int n){
   
   //build_maxHeap
    for(int i = parent(n-1); i>=0; i--){
        maxheapify(arr,n,i);
    }

    for(auto i = n-1; i>=1; i--){
        swap(arr[i],arr[0]);
        maxheapify(arr,i,0);
    }

}

int main(){

    vector<int> v = {10,15,50,4,20};
    int n =v.size();
    heapSort(v,n);

    cout<<endl;
    for(auto x:v){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}