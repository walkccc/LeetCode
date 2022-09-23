class Solution {
 public:
  int constrainedSubsetSum(vector<int>& nums, int k) {
    // dp[i] := max sum of non-empty subsequence in nums[0..i]
    vector<int> dp(nums.size());
    // q stores dp[i - k], dp[i - k + 1], ..., dp[i - 1] whose values are > 0 in
    // decreasing order
    deque<int> q;

    for (int i = 0; i < nums.size(); ++i) {
      if (q.empty())
        dp[i] = nums[i];
      else
        dp[i] = max(q.front(), 0) + nums[i];
      while (!q.empty() && q.back() < dp[i])
        q.pop_back();
      q.push_back(dp[i]);
      if (i >= k && dp[i - k] == q.front())
        q.pop_front();
    }

    return *max_element(begin(dp), end(dp));
  }
};
