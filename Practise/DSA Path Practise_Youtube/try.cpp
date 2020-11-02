


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

int nextGap(int gap)
{
    if (gap <= 1)
        return 0;
    return (gap / 2) + (gap % 2);
}
 
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

int main(int argc, char const *argv[])
{
	#ifdef ONLINE_JUDGE
	freopen("intput.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	#endif

	int n;
	cin>>n;
	int a[n];
	inputArray1D(a,n);
	int b[n];
	for(auto i=0;i<n;i++) b[i]=a[i];
	merge(a,b,n,n);
	print1DArray(a,n);

	return 0;
}



