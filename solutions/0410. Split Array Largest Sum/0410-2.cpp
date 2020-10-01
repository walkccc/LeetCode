class Solution {
 public:
  int splitArray(vector<int>& nums, int m) {
    const int n = nums.size();

    vector<vector<long>> memo(n + 1, vector<long>(m + 1, INT_MAX));
    vector<long> prefixSum(n + 1);  // prefixSum[i] := sum of nums[0..i)

    for (int i = 1; i <= n; ++i)
      prefixSum[i] += prefixSum[i - 1] + nums[i - 1];

    // dp(n, m) := min of largest sum to split nums[0..n) into m groups
    function<long(int, int)> dp = [&](int n, int m) {
      if (m == 1) return prefixSum[n];
      long& ans = memo[n][m];
      if (ans < INT_MAX) return ans;

      // try all possible partitions
      for (int i = m - 1; i < n; ++i)
        ans = min(ans, max(dp(i, m - 1), prefixSum[n] - prefixSum[i]));

      return ans;
    };

    return dp(n, m);
  }
};