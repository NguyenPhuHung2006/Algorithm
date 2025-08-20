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

int MOD = 1e9 + 7;

// https://codeforces.com/problemset/problem/431/C

void solve() 
{
	int n, k, d;
	cin >> n >> k >> d;
	vll dp(n + 1);

	dp[1] = 1;
	int start = 1;

	for(int i = 2; i <= n; i++)
	{
		ll cur = 0;
		if(i <= k)
			cur++;

		start = max(1, i - k);
		for(int j = start; j < i; j++)
			cur += dp[j];
		
		dp[i] = cur;
	}
	
	int end = max(d, start);
	ll res = dp[n];
	for(int i = start; i < end; i++)
		res -= dp[i];

	cout << res % MOD << '\n';
}


int main() 
{
    fastio;
    int t = 1;
    // cin >> t;
    while (t--) 
		solve();
    return 0;
}

