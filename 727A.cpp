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
#include <random>

using namespace std;

// ---------- Macros & Typedefs ----------
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)

using ll = long long;

void solve() 
{
	int a, b;
	cin >> a >> b;
	vector<int> res{b};
	while(b > a)
	{
		if(b % 2 == 0)
			b /= 2;
		else if(b % 10 == 1)
			b /= 10;
		else
			break;
		res.push_back(b);
	}
	if(b != a)
	{
		cout << "NO";
		return;
	}
	cout << "YES\n";
	cout << res.size() << '\n';
	for(int i = res.size() - 1; i >= 0; i--)
	{
		cout << res[i] << " ";
	}
}

int main() 
{
    fastio;
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}

