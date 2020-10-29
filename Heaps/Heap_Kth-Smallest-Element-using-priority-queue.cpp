/*
Given row and coloumn sorted elements,
find kth smallest element.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int , pair <int,int> > node;

/*
      <  value  ,    <  i  ,   j  > >
*/

node smallestinMatrix(vector < vector <int> > arr, int x , priority_queue < node, vector<node> , greater <node> > pq )
{
    node element = pq.top();
    int i = element.second.first;
    int j = element.second.second;

    if(j == arr[i].size()-1 && i == arr.size()-1)
        {
            cout<<"End of matrix reached"<<endl;
            return element;
        }
    
    if(x==0)
    {
        return element;
    }

//we have not reached the end of array and we have not reached the kth element
  
    pq.pop();
    int right = 0,down = 0 ;
    
    int k = 0;
    //k = 0 for down and 1 for right

    node ans;

    if(j+1 <= arr[i].size()-1)
        right = 1;
    
    if(i+1 <= arr.size()-1) 
        down = 1; 

    if(right && down) // we can go both right and down
    {
        if(arr[i][j+1] < arr[i+1][j]) // checking where to go
            k = 1;
        else
            k = 0;         
    }

    else if( right )  // only right possible
    {
        k = 1;
    }

    else if( down ) // only down possible
    {
        k = 0;
    }

    else // nowhere to go -- end of array
    {
        k = -1;   
    }
    
    if (k == 0)
    { 
        pq.push(make_pair(arr[i+1][j] , make_pair(i+1 , j)));
    }

    else if (k == 1)
    {
        pq.push(make_pair(arr[i][j+1] , make_pair(i , j+1)));
    }

    ans = smallestinMatrix(arr, x-1 , pq);

    return ans;
}

node KthsmallestinSortedMatrix(vector < vector <int> > arr, int k)
{
    priority_queue < node, vector<node> , greater <node> > pq;
    
    for(int i=0;i<arr[0].size();i++)
    {
        pq.push(make_pair(arr[0][i] , make_pair(0 , i)));
    }

node answer;

    answer = smallestinMatrix(arr,k,pq);
    return answer;
}

int main()
{
    //find kth smallest element in a row and coloumn sorted matrix
    vector < vector<int> > arr = 
    {
         {1,  5,  9},
         {10, 11, 13},
         {12, 13, 15}
    };

    int k=3;
    node ans = KthsmallestinSortedMatrix(arr , k);
    cout << ans.first << endl;
}