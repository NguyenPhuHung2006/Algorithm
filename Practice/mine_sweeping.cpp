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

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)
using ll = long long;
bool has_mutiple_tests = false;

/* 3 3 */
/* 1 1 1 */
/* 2 2 3 */
/* 2 2 2 */

int m, n;

pair<int,int> pos(int idx)
{
	return {idx / m, idx % m};
}

void unassign(vector<vector<int>>& a, vector<vector<bool>>& res, int i, int j)
{
	res[i][j] = false;
	for(int r = max(0, i - 1); r <= min(n - 1, i + 1); r++)
	{
		for(int c = max(0, j - 1); c <= min(m - 1, j + 1); c++)
		{
			if(r == i && c == j)
				continue;
			a[r][c]++;
		}
	}
}

bool assign(vector<vector<int>>& a, vector<vector<bool>>& res, int i, int j)
{
	res[i][j] = true;
	bool valid = true;
	for(int r = max(0, i - 1); r <= min(n - 1, i + 1); r++)
	{
		for(int c = max(0, j - 1); c <= min(m - 1, j + 1); c++)
		{
			if(r == i && c == j)
				continue;
			if(--a[r][c] < 0)
				valid = false;
		}
	}
	if(valid)
		return true;
	
	unassign(a, res, i, j);
	return false;
}

bool backtrack(vector<vector<int>>& a, vector<vector<bool>>& res, int idx = 0)
{
	if(idx == m * n)
		return true;

	pair<int,int> p = pos(idx);
	if(assign(a, res, p.first, p.second))
	{
		if(backtrack(a, res, idx + 1))
			return true;
		unassign(a, res, p.first, p.second);
		return backtrack(a, res, idx + 1);
	}
	return false;
}

void solve() 
{
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> a[i][j];

	vector<vector<bool>> res(n, vector<bool>(m, false));
	bool solvable = backtrack(a, res);

	if(solvable)
	{
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				cout << res[i][j] << " ";
			}
			cout << '\n';
		}
	}
}

int main() 
{
    fastio;     
    int t = 1;
	if(has_mutiple_tests)
	    cin >> t;
    while (t--) 
		solve();
    return 0;
}

