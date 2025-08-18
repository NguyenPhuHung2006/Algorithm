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
	int n, k;
	cin >> n >> k;
	int cnt = 0, maxMod = 0;
	bool check = false;
	while(n--)
	{
		int t;
		cin >> t;
		if(t % 2 == 0)
			cnt++;
		int mod = t % k;
		if(mod == 0)
			check = true;
		maxMod = max(maxMod, mod);
	}
	if(check)
		cout << 0;
	else if(k != 4)
		cout << k - maxMod;
	else
	{
		if(cnt == 0)
			cout << min(2, k - maxMod);
		else if(cnt == 1)
			cout << 1;
		else
			cout << 0;
	}
	cout << '\n';
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

