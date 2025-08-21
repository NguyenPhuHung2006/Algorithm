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
	ll n;
	cin >> n;
	
	vll res;
	ll i = 11;
	while(i <= n)
	{
		if(n % i == 0)
			res.push_back(n / i);
		if (i > (LLONG_MAX) / 10) 
			break;
		i = 10 * i - 9;
	}
	reverse(all(res));
	cout << res.size() << '\n';
	for(int i = 0; i < res.size(); i++)
	{
		cout << res[i] << (i + 1 == res.size() ? '\n' : ' ');
	}
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

