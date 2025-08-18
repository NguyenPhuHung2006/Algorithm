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
	string s = "";
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	bool flip = true;
	int l = 0, r = n - 1;
	while(l <= r)
	{
		if(flip)
		{
			if(a[l] < a[r])
			{
				s += 'L';
				l++;
			}
			else
			{
				s += 'R';
				r--;
			}
		}
		else
		{
			if(a[l] < a[r])
			{
				s += 'R';
				r--;
			}
			else
			{
				s += 'L';
				l++;
			}
		}
		flip = flip ^ 1;
	}
	cout << s << '\n';
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
