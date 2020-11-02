


#include <bits/stdc++.h>
using namespace std;

 void reverse(int[] nums, int start) {
        int i = start, j = nums.length - 1;
        while (i < j) {
            swap(nums, i, j);
            i++;
            j--;
        }
    }

     void nextPermutation(int[] nums) {
        int i = nums.length - 2;
        while (i >= 0 && nums[i + 1] <= nums[i]) {
            i--;
        }
        if (i >= 0) {
            int j = nums.length - 1;
            while (j >= 0 && nums[j] <= nums[i]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums, i + 1);
    }

int main(int argc, char const *argv[])
{
    #ifdef ONLINE_JUDGE
    freopen("intput.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    #endif
    
int n;
cin>>n;
int nums[n];
for(auto i=0;i<n;i++){ cin>>nums[i];}
nextPermutation(nums);
    return 0;
}





    

    
