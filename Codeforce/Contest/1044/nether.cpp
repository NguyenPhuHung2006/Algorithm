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

	vector<pair<int,int>> len(n + 1);
	int maxLen = 0;
	for(int i = 1; i <= n; i++)
	{
		cout << "? " << i << " " << n << " ";
		for(int j = 1; j <= n; j++)
			cout << j << " ";

		cout << endl;
		cout.flush();
		int l;
		cin >> l;
		len[i] = {i, l};
		maxLen = max(maxLen, l);
	}

	vector<vector<int>> bucket(maxLen + 1);
	for(auto p : len)
		bucket[p.second].push_back(p.first);

	vector<int> res(maxLen);
	int start = bucket[maxLen].back();
	res[maxLen - 1] = start;
	for(int i = maxLen - 1; i >= 1; i--)
	{
		for(int next : bucket[i])
		{
			cout << "? " << start << " 2 " << start << " " << next << endl;
			cout.flush();
			int l;
			cin >> l;
			if(l == 2)
			{
				res[i - 1] = next;
				start = next;
				break;
			}
		}
	}

	cout << "! " << maxLen << " ";
	for(int i = maxLen - 1; i >= 0; i--)
		cout << res[i] << " ";

	cout << endl;
	cout.flush();

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

