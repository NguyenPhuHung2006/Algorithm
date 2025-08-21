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


void solve() {
    long long n;
    cin >> n;

    // find largest exponent of 3
    long long p = 1;
    int start = 0;
    while (p * 3 <= n) {
        p *= 3;
        start++;
    }

    long long res = 0;
    for (int i = start; i >= 0; i--) {
        long long num = n / p;
        if (num > 0) {
            // check if this is the intended formula
            res += num * (3 * p + i * (p / 3));
            n -= num * p;
        }
        p /= 3; // next smaller power of 3
        if (n <= 0) break;
    }
    cout << res << '\n';
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

