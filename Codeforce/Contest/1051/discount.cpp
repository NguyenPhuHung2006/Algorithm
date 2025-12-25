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
bool has_mutiple_tests = true;

void solve() 
{
	int n, k;
	cin >> n >> k;
	vector<int> a(n), b(k);
	for(int& i : a)
		cin >> i;
	for(int& i : b)
		cin >> i;

	sort(a.rbegin(), a.rend());
	sort(b.begin(), b.end());

	int res = 0, i = 0, j = 0;
	
	while(i < n && j < k)
	{
		int end = min(i + b[j] - 2, n - 1);
		int cur = 0;

		while(i <= end)
			cur += a[i++];

		res += cur;
		j++;
		i++;
	}
	
	while(i < n)
		res += a[i++];

	cout << res << '\n';
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

