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
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using ll   = long long;
using pii  = pair<int,int>;
using pll  = pair<ll,ll>;
using vi   = vector<int>;
using vll  = vector<ll>;
using vvi  = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using vstr = vector<string>;
using vb   = vector<bool>;
using vvb  = vector<vector<bool>>;

void dfs(int cur, vector<vector<pii>>& edges, vb& visited, vi& res)
{
    if(edges[cur].empty() || visited[cur])
        return;
    
    visited[cur] = true;
    
    for(pii next : edges[cur])
    {
        if(!visited[next.first])
        {
            res.push_back(next.second);
            dfs(next.first, edges, visited, res);
        }
    }
}

void solve() 
{
    int n;
    cin >> n;
    vb visited(2 * n + 1, false);
    vector<vector<pii>> edges(2 * n + 1);
    vi res;

    for(int i = 1; i <= n; i++)
    {
        int u, v;
        cin >> u >> v;
        edges[u].push_back({v, i});
        edges[v].push_back({u, i});
    }

    for(int i = 1; i <= 2 * n; i++)
        dfs(i, edges, visited, res);
    
    cout << res.size() << '\n';

    for(int r : res)
        cout << r << " ";
    
    cout << '\n';

}

bool multiple_testcases = true;

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