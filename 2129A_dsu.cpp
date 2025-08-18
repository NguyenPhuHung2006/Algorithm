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
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using ll   = long long;
using pii  = pair<int,int>;
using pll  = pair<ll,ll>;
using vi   = vector<int>;
using vll  = vector<ll>;
using vvi  = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using vstr = vector<string>;
using vb   = vector<bool>;
using vvb  = vector<vector<bool>>;

struct DSU
{
	vector<int> parent, size;
	DSU(int n)
	{
		parent.resize(n + 1);
		size.assign(n + 1, 1);
		for(int i = 1; i <= n; i++)
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
			if(size[pu] > size[pv])
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
	int n;
	cin >> n;
	vector<tuple<int,int,int>> edges(n);
	vi res;
	
	for(int i = 0; i < n; i++)
	{
		int v1, v2;
		cin >> v1 >> v2;
		edges[i] = {v1, v2, i + 1};
	}

	DSU dsu(2 * n);

	for(auto edge : edges)
	{
		int u = get<0>(edge), v = get<1>(edge), i = get<2>(edge);
		if(!dsu.connected(u, v))
		{
			res.push_back(i);
			dsu.unite(u, v);
		}
	}

	cout << res.size() << '\n';
	for(int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	cout << '\n';
}

bool multiple_testcases = true;

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
