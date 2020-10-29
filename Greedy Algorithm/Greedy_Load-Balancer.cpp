//SPOJ - BALIFE - Load Balancing
/*
Given number of jobs on n processors.
Find if stte where each processor has same no. of jobs is possible
Find minimal number of round it will take to balance jobs on each processor
*/

#include <bits/stdc++.h>
using namespace std;

/*

We need to find maximum number of jobs transferred at any given time to find the minimum number of times the jobs are transferred

*/

int main(int argc, char const *argv[])
{
	#ifdef ONLINE_JUDGE
	freopen("intput.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	#endif

	int n;
	cin>>n;

	//whole system undergoes rebalancing if single processor load increases
	int jobs[n];
	int fjobs=0;
	for(auto i=0; i<n; i++) 
	{
		cin>>jobs[i];
		fjobs+=jobs[i];
	}

	if(fjobs%n!=0)
	{
		cout<<"NO PROCESSOR";
		return 0;
	}

	fjobs = fjobs/n;



	return 0;
}
