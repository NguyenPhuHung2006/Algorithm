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
	int n, a, b;
	cin >> n >> a >> b;

	auto even = [](int i) -> bool {
		return i % 2 == 0;
	};

	if(even(n))
	{
		if((even(a) && even(b)) || (!even(a) && even(b) && b > a))
			cout << "YES";
		else 
			cout << "NO";
	}
	else
	{
		if((!even(a) && !even(b)) || (even(a) && !even(b) && b > a))
			cout << "YES";
		else
			cout << "NO";
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

