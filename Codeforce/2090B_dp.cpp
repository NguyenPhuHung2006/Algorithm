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
	int R, C;
	cin >> R >> C;
	vstr grid(R);

	for(int r = 0; r < R; r++)
	{
		cin >> grid[r];
	}
	
	vvi dp(R, vi(C)); // 1: up, 2: left, 3: both

	for(int r = 0; r < R; r++)
	{
		for(int c = 0; c < C; c++)
		{
			if(grid[r][c] == '1')
			{
				bool up = false, left = false;
				if(r - 1 < 0 || dp[r - 1][c] == 3 || (grid[r - 1][c] == '1' && dp[r - 1][c] == 1))
					up = true;
				if(c - 1 < 0 || dp[r][c - 1] == 3 || (grid[r][c - 1] == '1' && dp[r][c - 1] == 2))
					left = true;
				if(up || left)
				{
					if(up && left)
						dp[r][c] = 3;
					else if(left)
						dp[r][c] = 2;
					else
						dp[r][c] = 1;
				}
				else
				{
					cout << "NO\n";
					return;
				}
			}
		}
	}
	cout << "YES\n";
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

