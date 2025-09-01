#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <tuple>
#include <numeric>
#include <functional>
#include <iomanip>
#include <cassert>
#include <bitset>
#include <limits>

using namespace std;

// ---------- Macros & Typedefs ----------
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)

using ll = long long;

bool multiple_testcases = true;

void solve() 
{
	int n;
	cin >> n;
	vector<vector<int>> adj(n);
	vector<int> degree(n, 0);
	for(int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		u--; v--;

		adj[u].push_back(v);
		adj[v].push_back(u);
		degree[u]++;
		degree[v]++;
	}
	if(n <= 2)
	{
		cout << "0\n";
		return;
	}
	int numLeaf = 0, numLeafRoot = 0;
	for(int deg : degree)
		if(deg == 1) numLeaf++;

	for(vector<int> neigh : adj)
	{
		int curLeaf = 0;
		for(int node : neigh)
		{
			if(degree[node] == 1)
				curLeaf++;
		}
		numLeafRoot = max(numLeafRoot, curLeaf);
	}
	cout << numLeaf - numLeafRoot << '\n';
}

int main() 
{
    fastio;     
    int t = 1;
	if(multiple_testcases)
	    cin >> t;
    while (t--) 
		solve();
    return 0;
}

