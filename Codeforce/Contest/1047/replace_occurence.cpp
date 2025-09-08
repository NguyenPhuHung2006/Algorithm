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
	unordered_map<int,int> freq;
	for(int& i : a)
	{
		cin >> i;
		freq[i]++;
	}

	int val = 0;
	vector<vector<int>> bucket(n + 1, vector<int>());
	for(pair<int,int> f : freq)
	{
		if(f.second % f.first != 0 || f.first > n)
		{
			cout << "-1\n";
			return;
		}
		for(int i = 0; i < f.second; i++)
		{
			if(i % f.first == 0)
				val++;
			bucket[f.first].push_back(val);
		}
	}

	for(int i : a)
	{
		cout << bucket[i].back() << " ";
		bucket[i].pop_back();
	}
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

