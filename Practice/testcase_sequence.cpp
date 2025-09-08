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

bool found = false;
int t = 3;

void print(vector<int> v)
{
	for(int u : v)
		cout << u << " ";
	cout << '\n';
}

void dfs(int i, vector<int> v = vector<int>())
{
	if(v.size() == i)
	{
		t--;
		if(!t)
		{
			print(v);
			found = true;
		}
		return;
	}

	for(int j = 0; j <= i; j++)
	{
		v.push_back(j);
		dfs(i, v);
		v.pop_back();
	}

}

int main() 
{
    fastio;     
	
	for(int i = 2; ; i++)
	{
		if(found)
			return 0;
		dfs(i);
	}
		
}

