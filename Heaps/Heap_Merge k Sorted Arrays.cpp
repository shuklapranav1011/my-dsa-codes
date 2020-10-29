#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair <int , pair<int,int> > node;


/*  
                  P  
    value                      P
                          i           j
*/  


vector <int> mergeKsortarrays(vector <vector <int> >  arr)
{
    vector <int> result;
    priority_queue <node , vector <node> , greater <node> > pq;
   
    /*
        first element of node is of type int so greater can
        make a comparison here. Else we would use functors.
    */

   for(int i=0;i<arr.size();i++)
   {
       pq.push( arr[i][0] , make_pair( i , 0 ) );
   }

   //remove the elements one by one and add to result

   while(!pq.empty());
   {
       node current = pq.top();
       pq.pop();
       int element = current.first;
       int i = current.second.first;
       int j = current.second.second;

       result.push_back(element);

       //push the next element of current element

       if(j+1 < arr[i].size())
       {
        pq.push( arr[i][j+1], make_pair( i , j+1 ) );
       }
   }
   return result;
}

int main()
{
    //given k sorted array
    //sort the elements

    //Extending merge function to work on k sorted arrays

}