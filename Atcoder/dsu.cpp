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

bool multiple_testcases = false;

struct DSU
{
	vector<int> parent, size;
	DSU(int n)
	{
		parent.resize(n);
		size.resize(n, 1);
		for(int i = 0; i < n; i++)
			parent[i] = i;
	}

	int find(int u)
	{
		if(u != parent[u])
			parent[u] = find(parent[u]);
		return parent[u];
	}

	void unite(int u, int v)
	{
		int pu = find(u), pv = find(v);
		if(pu != pv)
		{
			if(size[pu] >= size[pv])
			{
				size[pu] += size[pv];
				parent[pv] = pu;
			}
			else
			{
				size[pv] += size[pu];
				parent[pu] = pv;
			}
		}
	}

	bool connected(int u, int v)
	{
		return find(u) == find(v);
	}
};

void solve() 
{
	int n, q;
	cin >> n >> q;

	DSU dsu(n);

	while(q--)
	{
		int t, u, v;
		cin >> t >> u >> v;
		if(t == 0)
			dsu.unite(u, v);
		else
			cout << (dsu.connected(u, v) ? 1 : 0) << '\n';
	}
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

