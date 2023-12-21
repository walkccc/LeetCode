class Solution {
 public:
  long long minCost(vector<int>& nums, vector<int>& costs) {
    const int n = nums.size();
    // dp[i] := the minimum cost to jump to i
    vector<long long> dp(n, LLONG_MAX);
    stack<int> maxStack;
    stack<int> minStack;

    dp[0] = 0;

    for (int i = 0; i < n; ++i) {
      while (!maxStack.empty() && nums[i] >= nums[maxStack.top()])
        dp[i] = min(dp[i], dp[maxStack.top()] + costs[i]), maxStack.pop();
      while (!minStack.empty() && nums[i] < nums[minStack.top()])
        dp[i] = min(dp[i], dp[minStack.top()] + costs[i]), minStack.pop();
      maxStack.push(i);
      minStack.push(i);
    }

    return dp.back();
  }
};
