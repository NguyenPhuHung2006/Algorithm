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
	vector<ll> h(n + 1);
	for(int i = 1; i <= n; i++)
		cin >> h[i];

	vector<ll> dp(n + 1);
	dp[0] = 0;
	dp[1] = h[1];

	for(int i = 2; i <= n; i++)
		dp[i] = min(dp[i - 1] + h[i] - 1, dp[i - 2] + h[i - 1] + max(0LL, h[i] - 1LL * (i - 1)));

	cout << dp[n] << '\n';

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

