#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// Function to find inversion count in the array

// arr[]: Input Array
// N : Size of the Array arr[]

typedef ll long long long long merge(long long arr[], long long temp[], long long left, long long mid, long long right)
{

    ll i = left;
    ll j = mid;

    ll k = left;
    ll inv_count = 0;

    while (i <= mid - 1 && j <= right)
    {
        if (arr[i] > arr[j])
        {
            temp[k++] = arr[j++];
            inv_count += mid - i;
        }
        else
        {
            temp[k++] = arr[i++];
        }
    }

    while (i <= mid - 1)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (int l = left; l <= right; l++)
        arr[l] = temp[l];

    return inv_count;
}

long long mergeSort(long long arr[], long long temp[], long long left, long long right)
{
    long long inv_count = 0;
    long long mid = (left + right) / 2;

    if (left < right)
    {
        inv_count += mergeSort(arr, temp, left, mid);
        inv_count += mergeSort(arr, temp, mid + 1, right);

        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}

long long int inversionCount(long long arr[], long long N)
{
    long long temp[N];
    return mergeSort(arr, temp, 0, N - 1);
}

// { Driver Code Starts.

int main()
{

    long long T;
    cin >> T;

    while (T--)
    {
        long long N;
        cin >> N;

        long long A[N];
        for (long long i = 0; i < N; i++)
        {
            cin >> A[i];
        }

        cout << inversionCount(A, N) << endl;
    }

    return 0;
}
// } Driver Code Ends
