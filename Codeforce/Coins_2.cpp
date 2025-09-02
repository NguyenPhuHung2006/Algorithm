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

bool multiple_testcases = false;

vector<int> sieve_spf(int n)
{
	vector<int> spf(n + 1, 1);

	int end = sqrt(n);
	for(int i = 2; i <= end; i++)
	{
		if(spf[i] == 1)
		{
			for(int j = i * i; j <= n; j += i)
			{
				if(spf[j] == 1)
					spf[j] = i;
			}
		}
	}
	return spf;
}

void solve() 
{
	int n;
	cin >> n;
	
	vector<int> spf = sieve_spf(n);

	while(true)
	{
		cout << n << " ";
		if(n == 1)
			break;
		if(spf[n] == 1)
		{
			cout << 1;
			break;
		}
		n /= spf[n];
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

