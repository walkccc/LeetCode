class Solution {
 public:
  int constrainedSubsetSum(vector<int>& nums, int k) {
    int ans = INT_MIN;
    vector<int> dp(nums.size());
    deque<int> q;

    for (int i = 0; i < nums.size(); ++i) {
      if (q.empty())
        dp[i] = nums[i];
      else
        dp[i] = max(q.front(), 0) + nums[i];
      ans = max(ans, dp[i]);
      while (!q.empty() && q.back() < dp[i])
        q.pop_back();
      q.push_back(dp[i]);
      if (i >= k && dp[i - k] == q.front())
        q.pop_front();
    }

    return ans;
  }
};