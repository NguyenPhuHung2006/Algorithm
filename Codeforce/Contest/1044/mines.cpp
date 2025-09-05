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

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)
using ll = long long;
bool has_mutiple_tests = true;

const int GREEN  = 0;
const int YELLOW = 1;

vector<vector<int>> adj;
vector<int> color; 
vector<pair<int,int>> res;
vector<int> leaves;

void AddColor(int cur, int parent)
{
	vector<int> children;
	for(int next : adj[cur])
	{
		if(next != parent)
		{
			children.push_back(next);
			AddColor(next, cur);
		}
	}
	int countGreen = 0;
	bool hasYellow = false;

	for(int child : children)
	{
		if(color[child] == GREEN)
			countGreen++;
		else if(color[child] == YELLOW)
			hasYellow = true;
	}

	if(hasYellow || countGreen >= 3)
	{
		res.push_back({2, cur + 1});
		res.push_back({1, cur + 1});
	}
	else if(countGreen == 2)
		color[cur] = YELLOW;
	else 
	{
		color[cur] = GREEN;
		if(countGreen == 0)
			leaves.push_back(cur);
	}
}

void dfs(int cur, int parent)
{
	res.push_back({1, cur + 1});
	color[cur] = -1;
	for(int next : adj[cur])
	{
		if(next != parent && color[next] != -1)
			dfs(next, cur);
	}
}

void solve() 
{
	int n;
	cin >> n;
	adj.assign(n, vector<int>());
	color.assign(n, -1);
	res.clear();
	leaves.clear();

	int e = n - 1;
	while(e--)
	{
		int u, v;
		cin >> u >> v;
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	AddColor(0, -1);

	for(int leaf : leaves)
	{
		if(color[leaf] != -1)
			dfs(leaf, -1);
	}

	cout << res.size() << '\n';
	for(pair<int,int> r : res)
		cout << r.first << " " << r.second << '\n';
}

int main() 
{
    fastio;     
    int t = 1;
	if(has_mutiple_tests)
	    cin >> t;
    while (t--) 
		solve();
    return 0;
}

