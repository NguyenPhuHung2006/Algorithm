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
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	auto valid = [](int a, int b) -> bool {
		return max(a, b) <= 2 * min(a, b) + 2;
	};
	bool isDream = valid(a, b) && valid(c - a, d - b);
	cout << (isDream ? "YES" : "NO") << '\n';
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

