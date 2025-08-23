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

// https://codeforces.com/problemset/problem/431/C

ll mod = 1e9 + 7;

vector<pair<ll,ll>> cache;

pair<ll,ll> dfs(int n, int k, int d)
{
	if(n == 0)
		return {1, 0};
	if(cache[n].first != -1)
		return cache[n];

	ll res1 = 0, res2 = 0;
	for(int t = 1; t <= k; t++)
	{
		if(t > n)
			break;
		bool curValid = t >= d;
		pair<ll,ll> next = dfs(n - t, k, d);

		res1 = (res1 + next.first) % mod;
		if(curValid)
			res2 = (res2 + next.first) % mod;
		else
			res2 = (res2 + next.second) % mod;
	}
	return cache[n] = {res1, res2};
}

void solve() 
{
	int n, k, d;
	cin >> n >> k >> d;

	cache.assign(n + 1, {-1, -1});

	pair<ll,ll> res = dfs(n, k, d);
	cout << res.second % mod;
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

