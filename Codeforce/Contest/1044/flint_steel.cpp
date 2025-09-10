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

template<class T>
class SegmentTree
{
private:
	vector<T> tree;
	int N;
public:
	SegmentTree(const vector<T>& a) : N(a.size())
	{
		tree.resize(2 * N);
		for(int i = 0; i < N; i++)
			tree[N + i] = a[i];

		for(int i = N - 1; i >= 1; i--)
			tree[i] = T::combine(tree[i << 1], tree[i << 1 | 1]);
	}

	void update(int i, T val)
	{
		tree[N + i] = val;
		for(int j = (N + i) >> 1; j >= 1; j >>= 1)
			tree[j] = T::combine(tree[j << 1], tree[j << 1 | 1]);
	}

	T query(int l, int r)
	{
		T res;
		for(l += N, r += N; l <= r; l >>= 1, r >>= 1)
		{
			if(l & 1)
				res = T::combine(res, tree[l++]);
			if(!(r & 1))
				res = T::combine(res, tree[r--]);
		}
		return res;
	}
};

struct Interval
{
	int L, R, idx, len;
	Interval(int l, int r, int i, int len) : L(l), R(r), idx(i), len(len) {}
	Interval() = default;
	bool operator==(const Interval& other) const
	{
		return L == other.L && R == other.R && idx == other.idx;
	}
};

struct IntervalHash 
{
	size_t operator()(const Interval& iv) const noexcept 
	{
		size_t h1 = std::hash<int>()(iv.L);
		size_t h2 = std::hash<int>()(iv.R);
		size_t h3 = std::hash<int>()(iv.idx);
		return h1 ^ (h2 << 1) ^ (h3 << 2);
	}
};

struct Node
{
	Interval itv;
	Node(Interval& itv) : itv(itv) {}

	static Node combine(const Interval& a, const Interval& b)
	{
		
	}

	static Node valid(const Interval& a, const Interval& b)
	{
		auto[La, Ra, idxA, lenA] = a;
		auto[Lb, Rb, idxB, lenB] = b;

	}

};

void solve() 
{
	int n;
	cin >> n;
	vector<int> e(n);
	for(int& i : e)
		cin >> i;

	const int INF = 1e6;

	unordered_map<Interval,pair<Interval, int>, IntervalHash> mp;
	vector<Interval> intervals;
	Interval null(-1, -1, -1);
	vector<Interval> validIntervals;

	for(int i = 0; i < n; i++)
	{
		if(e[i] == 0)
			continue;
		int L = max(0, i - e[i] + 1);
		int R = min(n - 1, i + e[i] - 1);
		intervals.emplace_back(L, R, i);

		mp[intervals.back()] = {null, (L == 0 ? 1 : INF)};
		if(L == 0 && R == n - 1)
			validIntervals.push_back(intervals.back());
	}

	int N = intervals.size();
	for(int i = 0; i < N; i++)
	{
		auto[Li, Ri, idxI] = intervals[i];
		if(mp[intervals[i]].second != INF)
			continue;

		/* for(int j = 0; j < i; j++) */
		/* { */
		/* 	int len = mp[intervals[i]].second; */
		/* 	auto[Lj, Rj, idxJ] = intervals[j]; */
		/* 	int prevLen = mp[intervals[j]].second; */

		/* 	if(prevLen == INF || idxJ == -1 || Rj < Li - 1 || (Rj >= idxI && Li <= idxJ) || Rj >= Ri || Li <= Lj) */
		/* 		continue; */

		/* 	if(len > prevLen + 1) */
		/* 		mp[intervals[i]] = {intervals[j], prevLen + 1}; */
				
		/* } */
		if(intervals[i].R == n - 1 && mp[intervals[i]].second != INF)
			validIntervals.push_back(intervals[i]);
	}

	if(validIntervals.empty())
	{
		cout << "-1\n";
		return;
	}

	int len = INF;
	Interval res;
	for(Interval validInterval : validIntervals)
	{
		if(len > mp[validInterval].second)
		{
			res = validInterval;
			len = mp[validInterval].second;
		}
	}

	unordered_set<Interval, IntervalHash> vis;
	Interval cur = res;
	vector<int> ans;

	while(!(cur == null))
	{
		if(!vis.count(cur))
		{
			vector<int> store;
			store.push_back(cur.idx);
			Interval trav = cur;
			Interval prev = mp[trav].first;

			while(!(prev == null) && trav.L <= prev.idx)
			{
				store.push_back(prev.idx);
				vis.insert(prev);
				trav = prev;
				prev = mp[prev].first;
			}
			for(int i = (int)store.size() - 1; i >= 0; i--)
				ans.push_back(store[i] + 1);
		}
		cur = mp[cur].first;
	}

	cout << ans.size() << '\n';
	for(int a : ans)
		cout << a << " ";

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

