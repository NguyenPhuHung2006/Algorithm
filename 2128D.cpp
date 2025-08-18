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

void solve() 
{
	int n;
	cin >> n;
	vi a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];

	vector<pii> dp(n);
	dp[0] = {1, 1};

	if(a[0] > a[1])	
	{
		dp[1] = {4, 3};
		if(a[1] > a[2])
			dp[2] = {12, 7};
		else
			dp[2] = {4, 3};
	}
	else
	{
		dp[1] = {1, 1};
		if(a[0] > a[2])
			dp[2] = {6, 5};
		else
			dp[2] = {4, 3};
	}

	for(int i = 3; i < n; i++)
	{
		if(a[i - 2] > a[i - 1])
		{
			if(a[i - 1] > a[i])
				dp[i] = {2 * dp[i - 1].first + dp[i - 1].second + 1, 2 * dp[i - 1].second + 1};
			else
				dp[i] = {2 * dp[i - 2].first + dp[i - 2].second + 1, 2 * dp[i - 2].second + 1};
		}
		else
		{
			if(a[i - 2] > a[i])
				dp[i] = {2 * (dp[i - 2].first + dp[i - 1].first) + dp[i - 2].second + dp[i - 1].second + 1, 2 * (dp[i - 2].second + dp[i - 1].second) + 1};
			else
				dp[i] = {2 * dp[i - 1].first + dp[i - 1].second + 1, 2 * dp[i - 1].second + 1};
		}
		if(a[i - 3] < min(a[i - 2], a[i - 1]) && a[i - 3] > a[i])
		{
			dp[i].first += 2 * dp[i - 3].first + dp[i - 3].second + 1;
			dp[i].second += 2 * dp[i - 3].second + 1;
		}
	}

	cout << dp[n - 1].first << '\n';
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

