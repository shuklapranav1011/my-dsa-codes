
/*
Find the smallest substring containing all characters of another string.

String --> "helloeeo world"
Pattern --> "eelo"
*/

/*
1. Handle corner case in the beginning when pattern lenghth> string

2. Make a pattern frequency array and init it with freq of characters

3. Sring frequency

	Expand towards right to get the window, once you get the window you contract
fro, the left to avoid un-required character (either the char is not present in the pattern or
-- its freqqunce is higher than requrired)

4. Everytime we get a window we update the minimum window by doning a comparison b/w
curr_window and mini_window you got till now.

5.	Output the min window

*/



#include <bits/stdc++.h>
using namespace std;


string smallest_window(string s, string p)
{

	int sl = s.length();
	int pl = p.length();

	//1. Corner Case
	if(pl>sl)
		return "NONE"; 

	//2. Maps
	int fs[256] = {0};
	int fp[256] = {0};

	for(auto x: p)
		fp[x]++;

	//3. Sliding Window (Expansion + Contraction + Update the Mini Length Window)
	int cnt = 0; 
	int start = 0 ;	
	int min_len = INT_MAX;
	int start_idx = -1;

	for(int i=0;i<sl;i++)
	{
	    char ch = s[i];
		fs[ch]++;

		//Maintain the count of characters mapped
		if(fp[ch]!=0 && fs[ch] <= fp[ch])
			cnt++;

		//if all the characters match
		if(cnt == pl)
		{
			char temp = s[start];
			//Loop to remove all unwanted characters

// unwanted characters = characters not present in pattern + present in pattern but freq.> pattern 
			while(fp[temp] == 0 || fs[temp] > fp[temp])
			{
				fs[temp]--;
				start++;
				temp = s[start];
			}

			//window-size
			int window_length = i- start + 1;
			if(window_length < min_len)
			{
				min_len  = window_length;
				start_idx = start;
			}
		}
	}

	if(start_idx == -1)
	return "NONE";

	string ans = s.substr(start_idx,min_len);
	return ans;	

}


int main(int argc, char const *argv[])
{
	#ifdef ONLINE_JUDGE
	freopen("intput.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	#endif

string str = "helorelleo world";
string ele = "eloe";


cout<<smallest_window(str, ele);

	return 0;
}
