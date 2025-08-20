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

/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> cache;
    int n;

    bool dfs(vector<int>& nums, int target, int i = 0)
    {
        if(i >= n)
            return target == 0;
        if(target < 0)
            return false;
        if(cache[i][target] != -1)
            return cache[i][target];

        cache[i][target] = dfs(nums, i + 1, target) || dfs(nums, i + 1, target - nums[i]);
        return cache[i][target];
    }

    bool canPartition(vector<int>& nums) 
    {
        int target = 0;
        n = nums.size();
        for(int num : nums)
            target += num;
        if(target % 2 != 0)
            return false;

        target /= 2;
        cache.resize(n, vector<int>(target + 1, -1));
        return dfs(nums, target);
    }
};
// @lc code=end

