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

using ll  = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi  = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using vstr = vector<string>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;

void solve() 
{
	int R, C;
	cin >> R >> C;
	vstr grid(R);

	vvb visited(R, vb(C, false));

	for(int r = 0; r < R; r++)
	{
		cin >> grid[r];
	}

	for(int r = 0; r < R; r++)
	{
		if(grid[r][0] == '1')
		{
			int c = 0;
			while(c < C && grid[r][c] == '1')
			{
				visited[r][c] = true;
				c++;
			}
		}
	}

	for(int c = 0; c < C; c++)
	{
		if(grid[0][c] == '1')
		{
			int r = 0;
			while(r < R && grid[r][c] == '1')
			{
				visited[r][c] = true;
				r++;
			}
		}
	}

	for(int r = 0; r < R; r++)
	{
		for(int c = 0; c < C; c++)
		{
			if(grid[r][c] == '1' && !visited[r][c])
			{
				cout << "NO\n";
				return;
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

