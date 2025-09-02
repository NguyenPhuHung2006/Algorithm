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

// https://codeforces.com/contest/2114/problem/E

void dfs(vector<vector<int>>& adj, vector<ll>& a, vector<bool>& visited, vector<ll>& res, int u = 1, ll wMax = 0, ll wMin = 0)
{
	if(visited[u])
		return;
	visited[u] = true;
	res[u] = max(a[u], a[u] - wMin);
	for(int next : adj[u])
		dfs(adj, a, visited, res, next, max(a[u], a[u] - wMin), min(a[u], a[u] - wMax));
}

void solve() 
{
	int n;
	cin >> n;
	vector<ll> a(n + 1);
	vector<bool> visited(n + 1, false);
	for(int i = 1; i <= n; i++)
		cin >> a[i];

	vector<vector<int>> adj(n + 1);
	for(int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<ll> res(n + 1);
	dfs(adj, a, visited, res);
	for(int i = 1; i <= n; i++)
		cout << res[i] << " ";
	cout << '\n';
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

