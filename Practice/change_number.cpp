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

void solve() 
{
	string s;
	cin >> s;
	int sum = 0;
	for(char c : s)
		sum += (c - '0');

	int res = 0;
	for(int i = 0; i < s.size(); i++)
	{
		int b = (sum - (s[i] - '0')) % 3;		
		int r = (3 - b) % 3; // s[i] % 3 == r 
		res += (r == 0 ? 4 : 3);
		if(i == 0 && r == 0)
			res--;
		if((s[i] - '0') % 3 == r)
			res--;
	}
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

