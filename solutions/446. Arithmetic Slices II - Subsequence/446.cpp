class Solution {
 public:
  int numberOfArithmeticSlices(vector<int>& nums) {
    const int n = nums.size();
    int ans = 0;
    // dp[i][j] := the number of subsequences end in nums[j] nums[i]
    vector<vector<int>> dp(n, vector<int>(n));
    unordered_map<long, vector<int>> numToIndices;

    for (int i = 0; i < n; ++i)
      numToIndices[nums[i]].push_back(i);

    for (int i = 0; i < n; ++i)
      for (int j = 0; j < i; ++j) {
        const long target = nums[j] * 2L - nums[i];
        if (const auto it = numToIndices.find(target);
            it != numToIndices.cend())
          for (const int k : it->second)
            if (k < j)
              dp[i][j] += (dp[j][k] + 1);
        ans += dp[i][j];
      }

    return ans;
  }
};
