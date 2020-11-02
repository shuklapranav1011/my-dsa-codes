


#include <bits/stdc++.h>
using namespace std;


void inputArray1D(int *a,int n)
{
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
}

void print1DArray(int *a,int n)
{
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
		cout<<endl;
}


/*
TLE - Time Limit Exceeded 

Space Complexity: O(1)
Time Complexity: Gud but not as good as O(m+n*(log(m+n)) & O(m+n)

void merge(int a[], int b[], int n, int m) {
   int i=n-1;
   int j=m-1;
   
   while(i>=0 && j>=0){
       if(a[i]<=b[j]) j--;
       else{
           if(i==0) swap(a[i], b[j]);
           else{
               int temp=i;
               for(int k=i;k>=0;k--) if(a[k]>b[j]) temp = k;
               swap(a[temp],b[j]);
               i=n-1;
           }
      }
 }
*/



/*
Efficient Solution

Time Complexity:  O(m+n*(log(m+n))
Space Complexity: O(1)

The idea: We start comparing elements that are far from each other rather than adjacent. 
For every pass, we calculate the gap and compare the elements towards the right of the gap. Every pass, the gap reduces to the ceiling value of dividing by 2.

First example: 
a1[] = {3 27 38 43}, 
a2[] = {9 10 82}
Start with 
gap =  ceiling of (n+m)/2 = 4 
[This gap is for whole merged array]
3* 27 38 43   9* 10 82 
3 27* 38 43   9 10* 82
3 10 38* 43   9 27 82*

gap = 2:
3* 10 38* 43   9 27 82
3 10* 38 43*   9 27 82
3 10 38* 43   9* 27 82 
3 10 9 43*   38 27* 82
3 10 9 27   38* 43 82*

gap = 1:
3* 10* 9 27   38 43 82
3 10* 9* 27   38 43 82
3 9 10* 27*   38 43 82
3 9 10 27*   38* 43 82
3 9 10 27   38* 43* 82
3 9 10 27   38 43* 82*
Output : 3 9 10 27 38 43 82
*/

int nextGap(int gap)
{
    if (gap <= 1)
        return 0;
    return (gap / 2) + (gap % 2);
}

//how to merge two sorted arrays without using extra space
void merge(int* arr1, int* arr2, int n, int m)
{
    int i, j, gap = n + m;
    for (gap = nextGap(gap); gap > 0; gap = nextGap(gap)) {
        // comparing elements in the first array.
        for (i = 0; i + gap < n; i++)
            if (arr1[i] > arr1[i + gap])
                swap(arr1[i], arr1[i + gap]);
 
        // comparing elements in both arrays.
        for (j = gap > n ? gap - n : 0; i < n && j < m;
             i++, j++)
            if (arr1[i] > arr2[j])
                swap(arr1[i], arr2[j]);
 
        if (j < m) {
            // comparing elements in the second array.
            for (j = 0; j + gap < m; j++)
                if (arr2[j] > arr2[j + gap])
                    swap(arr2[j], arr2[j + gap]);
        }
    }
}

/*
Efficient Solution --- BEST

Time Complexity:  O(m+n)
Space Complexity: O(1)

Suppose we have a number A and we want to convert it to a number B and there is also a 
constrain that we can recover number A any time without using other variable.To achieve 
this we chose a number N which is greater than both numbers and add B*N int A.
so A --> A+B*N

To get number B out of (A+B*N) we devide (A+B*N) by N (A+B*N)/N = B.

To get number A out of (A+B*N) we take modulo with N (A+B*N)%N = A.

-> In short by taking modulo we get old number back and taking divide we new number.


void mergeArray(int a[], int b[], int n, int m)
{
    int mx = 0;
     
    // Find maximum element of both array
    for (int i = 0; i < n; i++) {
        mx = max(mx, a[i]);
    }
    for (int i = 0; i < m; i++) {
        mx = max(mx, b[i]);
    }
     
    // increment one two avoid collision of 0 and maximum
    // element of array in modulo operation
    mx++;
    int i = 0, j = 0, k = 0;
    while (i < n && j < m && k < (n + m)) {
         
        // recover back original element to compare
        int e1 = a[i] % mx;
        int e2 = b[j] % mx;
        if (e1 <= e2) {
             
            // update element by adding multiplication
            // with new number
            if (k < n)
                a[k] += (e1 * mx);
            else
                b[k - n] += (e1 * mx);
            i++;
            k++;
        }
        else {
             
            // update element by adding multiplication
            // with new number
            if (k < n)
                a[k] += (e2 * mx);
            else
                b[k - n] += (e2 * mx);
            j++;
            k++;
        }
    }
     
    // process those elements which are left in array a
    while (i < n) {
        int el = a[i] % mx;
        if (k < n)
            a[k] += (el * mx);
        else
            b[k - n] += (el * mx);
        i++;
        k++;
    }
     
    // process those elements which are left in array a
    while (j < m) {
        int el = b[j] % mx;
        if (k < n)
            b[k] += (el * mx);
        else
            b[k - n] += (el * mx);
        j++;
        k++;
    }
     
    // finally update elements by dividing
    // with maximum element
    for (int i = 0; i < n; i++)
        a[i] = a[i] / mx;
 
    // finally update elements by dividing
    // with maximum element
    for (int i = 0; i < m; i++)
        b[i] = b[i] / mx;
 
    return;
}

*/

int main(int argc, char const *argv[])
{
	#ifdef ONLINE_JUDGE
	freopen("intput.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	#endif
	int n,m;
	cin>>n>>m;
	int a[n],b[m];
	inputArray1D(a,n);
	inputArray1D(b,n);
	merge(a,b,n,m);
	print1DArray(a,n);
	print1DArray(b,n);

	return 0;
}



