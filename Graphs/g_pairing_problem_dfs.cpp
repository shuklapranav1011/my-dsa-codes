



#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int xC2(int n)
{
	int temp = n*(n-1);
	return temp/2;
}

template <typename T>

class Graph
{
	map <T, list<T>> m;
public:
	void addEdge(T x, T y)
	{
		m[x].push_back(y);
	}

	void connected_components_helper(T parent, T node, map<T, int> &c, map<T, bool> &visited)
	{
		for(auto nbr: m[node])
		{
			if(visited[nbr]!=true)
			{
				c[parent]++;
				visited[nbr] = true;
				connected_components_helper(parent, nbr, c, visited);
			}
		}
	}

	void f()
	{
		map<T, int> components;

		map<T, bool> visited;

		int cnt_components=0;
		int cnt_mbr = 0;

		for(auto x: m)
		{
			if(visited[x.first]!=true)
			{
				cnt_components++;
				T node = x.first;
				components[node]= 1;
				visited[node] = true;

				connected_components_helper(node, node, components, visited);
			}
			cnt_mbr++;
		}

		int ans;
		if(cnt_mbr<2)
		{			
			cout<<"0";
			return;
		}

		ans = xC2(cnt_mbr);
		int temp = 0;

		for(auto y: components)
		{
			int mbr = y.second;
			temp+= xC2(mbr);
		}

		cout<<ans-temp;
	}
};



int main(int argc, char const *argv[])
{
	#ifdef ONLINE_JUDGE
	freopen("intput.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	#endif

	Graph <int>g;

	int n,m;
	cin>>n>>m;
	int a[n] = {0};
	while(m--)
	{
		int x;		int y;

		cin>>x>>y;
		a[x] =1;
		a[y] =1;

		g.addEdge(x,y);
	}

	for(auto i=0;i<n;i++)
	{
		if(a[i]==0)
			g.addEdge(i,i);
		a[i]=1;
	}

g.f();

	return 0;
}
