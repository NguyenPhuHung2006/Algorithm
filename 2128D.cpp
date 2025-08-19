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

//https://codeforces.com/problemset/problem/2128/D

void solve() 
{
	int n;
	cin >> n;
	vi a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];

    ll total = 0, INF = 500001;
    int dp2 = 0, dp1 = 0;

    for(int i = 0; i < n; i++)
    {
        int prev1Val = (i - 1 >= 0 ? a[i - 1] : INF);
        int prev2Val = (i - 2 >= 0 ? a[i - 2] : INF);
        int curDp;
        if(a[i] > prev1Val)
            curDp = 1 + dp2;
        else if(a[i] > prev2Val)
            curDp = 1 + dp1;
        else    
            curDp = 1 + max(dp1, dp2);

        total += curDp;
        dp2 = dp1;
        dp1 = curDp;
    }

    ll res = total;

    for(int i = 0; i < n - 1; i++)
    {
        if(a[i] < a[i + 1])
            total--;
        else if(a[i] > a[i + 1])
            total -= n - i;
        res += total;
    }

    cout << res << '\n';
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

