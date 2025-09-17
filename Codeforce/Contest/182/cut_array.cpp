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
	for(auto& i : a)
		cin >> i;

	vector<int> prefixSum(n, 0);
	vector<int> suffixSum(n, 0);

	for(int i = 0; i < n; i++)
	{
		prefixSum[i] = a[i] + (i == 0 ? 0 : prefixSum[i - 1]);
		suffixSum[n - i - 1] = a[n - i - 1] + (i == 0 ? 0 : suffixSum[n - i]);
	}

	for(int l = 0; l < n; l++)
	{
		int left = prefixSum[l] % 3;
		for(int r = l + 2; r < n; r++)
		{
			int right = suffixSum[r] % 3;
			int mid = (prefixSum[r - 1] - prefixSum[l]) % 3;
			if((left != right && left != mid && right != mid) || (left == mid && mid == right))
			{
				cout << l + 1 << " " << r << '\n';
				return;
			}
		}
	}

	cout << "0 0\n";
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

