#include <iostream>
#include <algorithm>
using namespace std;
  int binarysearch(int a[], int beg, int last, int k){
        int cnt = 0;
        while(beg < last){
            int mid = a[beg] + a[last];
            if(mid > k)
                last = last-1;
            else if (mid < k)
                beg = beg+1;
            else
            {
                cnt += 1;
                if(a[beg]==a[last])
					cnt += 1;
                beg = beg+1;
            }
        }
        return cnt;
    }
    int getPairsCount(int arr[], int n, int k) {
			sort(arr,arr+n);
        return binarysearch(arr, 0, n-1, k );
        }
int main(){
	int n = 49;
	int k = 50;
	int arr[]={48 ,24 ,99 ,51 ,33 ,39 ,29 ,83 ,74 ,72 ,22 ,46 ,40 ,51 ,67 ,37 ,78 ,76 ,26 ,28 ,76 ,25 ,10 ,65 ,64 ,47 ,34 ,88 ,26 ,49 ,86 ,73, 73, 36 ,75, 5, 26, 4, 39, 99, 27, 12, 97, 67, 63, 15, 3, 92, 90};

    cout<<getPairsCount(arr,n,k)<<endl;
}
