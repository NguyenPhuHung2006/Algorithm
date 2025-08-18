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
	int cnt0 = 0, cnt1 = 0, sum = 0;
	for(int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		if(t == 0)
			cnt0++;
		else if(t == 1)
			cnt1++;
		else
			sum += t;
	}
	if(cnt0 == cnt1)
		sum += cnt0 * 2;
	else if(cnt0 > cnt1)
		sum += cnt1 * 2 + (cnt0 - cnt1);
	else
		sum += cnt0 * 2 + (cnt1 - cnt0);
	cout << sum << '\n';
}

int main() 
{
    fastio;
    int t = 1;
    cin >> t;
    while (t--) 
		solve();
    return 0;
}

