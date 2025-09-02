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
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto& i : a)
		cin >> i;

	unordered_set<int> st;

	for(int i : a)
	{
		if(st.count(i))
		{
			cout << "YES\n";
			return;
		}
		st.insert(i);
	}
	cout << "NO\n";
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

