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

ll mod = 1e9 + 7;

void add(ll& a, ll b)
{
	a += b;
	if(a >= mod)
		a -= mod;
}

void solve() 
{
	int n, k, d;
	cin >> n >> k >> d;
	vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));
	dp[0][1] = 0;
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++)
	{
		int end = min(k, i);
		for(int t = 1; t <= end; t++)
		{
			add(dp[i][1], dp[i - t][1]);
			
			if(t >= d)
				add(dp[i][1], dp[i - t][0]);
			else
				add(dp[i][0], dp[i - t][0]);
		}
	}
	cout << dp[n][1] % mod;
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

