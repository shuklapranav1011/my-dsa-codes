 #include <bits/stdc++.h>
 using namespace std;
 
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int m = intervals.size();
        vector<vector<int>> ans;
        
        sort(intervals.begin(),intervals.end());
        int start = intervals[0][0];
        int last = intervals[0][1];
        
        
        for(int i=1;i<m;i++){
				//intervals merging
				int flag = 1;
				
				//intervals not merging
				if((start < intervals[i][0] && last < intervals[i][1] && last < intervals[i][0]) || (start > intervals[i][0] && last > intervals[i][1] && start > intervals[i][1]))
					flag = 0;
				
				if(flag == 0){
					vector<int> temp;
					temp.push_back(start);
					temp.push_back(last);
					ans.push_back(temp);
					
					start = intervals[i][0];
					last = intervals [i][1];
				}
				
				else{
					start = min(intervals[i][0], start);
                    last = max(intervals[i][1],last);
				}
        }
		
		vector<int> temp;
		temp.push_back(start);
		temp.push_back(last);
		ans.push_back(temp);
					
		
        return ans;
    }
    
 int main(){
	 vector<vector <int>> a
	 {
		 {1,4},{0,2}
		 };
	 
	 vector<vector <int>> ans = merge(a);
	 int m = ans.size();
	 
	  for (int i = 0; i < m; i++) 
    {	
		
        for (int j = 0; j < 2 ;j++)
        {
            cout << ans[i][j] << " ";
        }    
        cout << endl;
    }
 }
