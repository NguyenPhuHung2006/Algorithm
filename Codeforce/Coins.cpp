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

void solve() 
{
	int n;
	cin >> n;

	vector<int> dp(n + 1, 2);
	vector<int> prev(n + 1, 1);

	for(int j = 2; j <= n / 2; j++)
	{
		for(int i = 2 * j; i <= n; i += j)
		{
			if(dp[i] < dp[j] + 1)
			{
				dp[i] = dp[j] + 1;
				prev[i] = j;
			}
		}
	}

	int cur = n;
	while(true)
	{
		cout << cur << " ";
		if(cur == 1)
			return;
		cur = prev[cur];
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

