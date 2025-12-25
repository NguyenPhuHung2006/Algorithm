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
	int n;
	cin >> n;
	vector<int> a(n);
	int l, r;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		if(a[i] == n)
			l = r = i;
	}

	while(l > 0 || r < n - 1)
	{
		int left = (l > 0 ? a[l - 1] : -1);
		int right = (r < n - 1 ? a[r + 1] : -1);
		
		if(left == a[l] - 1 || left == a[r] - 1)
			l--;
		else if(right == a[l] - 1 || right == a[r] - 1)
			r++;
		else
		{
			cout << "NO\n";
			return;
		}
	}

	cout << "YES\n";

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

