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

int Lcm(int a, int b)
{
	return (a * b) / Gcd(a, b);
}

void solve() 
{
	int a, b;
	cin >> a >> b;

	if(a == b)
	{
		cout << 0 << '\n';
		return;
	}

	int L = Lcm(a, b);
	if(a == L || b == L)
		cout << 1;
	else 
		cout << 2;
	cout << '\n';

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

