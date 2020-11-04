#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void longestPalindromeSubstring(string str){
    
    /*dp[i][j] will be 1 if substring from i to j is a palindrome*/

    int n=str.length();
    bool dp[n][n];
    memset(dp,false,sizeof(dp));

    int max_length_palin=1;
    int start=0;

//palin of length 1
    for(int i=0;i<n;i++){
        dp[i][i]=true;
        start=i;
        max_length_palin=1;
    }

//palin of length 2
    for(int i=0;i<n-1;i++){
        if(str[i]==str[i+1]){
            dp[i][i+1]=true;
            start=i;
            max_length_palin=2;
        }
    }

//palin of length >= 3
    for(int len_palin=3;len_palin<=n;len_palin++){

        for(int i=0;i<n-(len_palin-1);i++){
            int j=len_palin+i-1;
            //checking if palin
            if(dp[i+1][j-1] && str[i]==str[j]){
                dp[i][j]=true;

                if(len_palin>max_length_palin){
                    start=i;
                    max_length_palin=len_palin;
                }
            }
        }
    }

    for(int k=start;k<start+max_length_palin;k++)
        cout<<str[k];
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        string s; cin>>s;
        longestPalindromeSubstring(s);
    }
}