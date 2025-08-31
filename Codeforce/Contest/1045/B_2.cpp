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

int Gcd(int a, int b)
{
	while(b != 0)
	{
		int t = b;
		b = a % b;
		a = t;
	}
	return a;
}

void solve() 
{
	int n, k;
	cin >> n >> k;
	vector<ll> a(n);
	for(ll& i : a)
		cin >> i;

	int g = 1;
	while(Gcd(k, ++g) != 1);

	for(auto i : a)
	{
		while(i % g != 0)
			i += k;
		cout << i << " ";
	}
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

