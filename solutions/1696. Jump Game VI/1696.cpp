class Solution {
 public:
  int maxResult(vector<int>& nums, int k) {
    // max queue storing dp[i] within the bounds
    deque<int> dq{0};
    // dp[i] := max score to consider nums[0..i]
    vector<int> dp(nums.size());
    dp[0] = nums[0];

    for (int i = 1; i < nums.size(); ++i) {
      // Pop the index if it's out of bounds.
      if (dq.front() + k < i)
        dq.pop_front();
      dp[i] = dp[dq.front()] + nums[i];
      // Pop indices that won't be chosen in the future.
      while (!dq.empty() && dp[dq.back()] <= dp[i])
        dq.pop_back();
      dq.push_back(i);
    }

    return dp.back();
  }
};
