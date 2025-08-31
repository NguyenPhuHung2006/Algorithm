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
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int cnt = 0;
	for(char c : s)
	{
		if(c == '1')
			cnt++;
		else if(c == '0')
			cnt = 0;
		if(cnt == k)
		{
			cout << "NO\n";
			return;
		}
	}
	int num = 1;
	vector<int> res(n);
	for(int i = 0; i < n; i++)
	{
		if(s[i] == '1')
			res[i] = num++;
	}
	for(int i = 0; i < n; i++)
	{
		if(s[i] == '0')
			res[i] = num++;
	}
	cout << "YES\n";
	for(int r : res)
		cout << r << " ";
	cout << '\n';
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

