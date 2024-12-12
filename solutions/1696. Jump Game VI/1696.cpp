class Solution {
 public:
  int maxResult(vector<int>& nums, int k) {
    // Stores dp[i] within the bounds.
    deque<int> maxQ{0};
    // dp[i] := the maximum score to consider nums[0..i]
    vector<int> dp(nums.size());
    dp[0] = nums[0];

    for (int i = 1; i < nums.size(); ++i) {
      // Pop the index if it's out-of-bounds.
      if (maxQ.front() + k < i)
        maxQ.pop_front();
      dp[i] = dp[maxQ.front()] + nums[i];
      // Pop indices that won't be chosen in the future.
      while (!maxQ.empty() && dp[maxQ.back()] <= dp[i])
        maxQ.pop_back();
      maxQ.push_back(i);
    }

    return dp.back();
  }
};
