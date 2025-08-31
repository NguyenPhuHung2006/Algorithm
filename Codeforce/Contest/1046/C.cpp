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
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++)
		cin >> a[i];

	vector<int> dp(n + 1, 0);
	vector<deque<int>> dq(n + 1);

	for(int i = 1; i <= n; i++)
	{
		dp[i] = dp[i - 1];

		dq[a[i]].push_back(i);
		if(dq[a[i]].size() == a[i])
		{
			dp[i] = max(dp[i], dp[dq[a[i]].front() - 1] + a[i]);
			dq[a[i]].pop_front();
		}
	}
	
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

