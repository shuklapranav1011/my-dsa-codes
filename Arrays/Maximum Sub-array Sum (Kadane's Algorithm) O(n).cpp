/* Kadane's Algorithm
Kadane's Algorithm calculate the maximum subarray sum but it does not show the array containing it.
Pros- O(n) complexity
Cons- Cant represent subarray containing it*/

void kadane(int a[];int n)
{int s=0,k=0;

    for(int i=0;i<n;i++)
    {
        s=s+a[i];

    /* If the sum is negative then even if we add positive number to it the overall sum would decrease.
       Thus, we make it zero, that is we discard the negative sum and move on to the sum of next array elements. */

        if(s<0)
            s=0;

        k=max(s,k); // k stores maximum sub-array sum
    }
}
