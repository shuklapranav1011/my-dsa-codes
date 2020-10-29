#include <bits/stdc++.h>
using namespace std;

int lis(const vector<int> &V) {
    if (V.size() == 0) 
    	return 0;
    
    int longest[V.size() + 1];
    
    int maxLen = 1;
    
    memset(longest, 0, sizeof(longest));
    
    longest[0] = 1;
    
    for (int i = 1; i < V.size(); i++) {
        longest[i] = 1;
        for (int j = 0; j < i; j++) {
            if (V[j] < V[i]) 
            	longest[i] = max(longest[i], longest[j] + 1);
        }
        maxLen = max(maxLen, longest[i]);
    }
    
    return maxLen;
}

int main(int argc, char const *argv[])
{
	#ifdef ONLINE_JUDGE
	freopen("intput.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	#endif

vector<int> a = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
cout<<lis(a);
}
