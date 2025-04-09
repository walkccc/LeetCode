class Solution {
 public:
  int minCost(vector<int>& nums, int k) {
    constexpr int kMax = 1001;
    const int n = nums.size();
    // trimmedLength[i][j] := trimmed(nums[i..j]).length
    vector<vector<int>> trimmedLength(n, vector<int>(n));
    // dp[i] := the minimum cost to split nums[i..n)
    vector<int> dp(n + 1, INT_MAX / 2);

    for (int i = 0; i < n; ++i) {
      int length = 0;
      vector<int> count(kMax);
      for (int j = i; j < n; ++j) {
        if (++count[nums[j]] == 2)
          length += 2;
        else if (count[nums[j]] > 2)
          ++length;
        trimmedLength[i][j] = length;
      }
    }

    dp[n] = 0;

    for (int i = n - 1; i >= 0; --i)
      for (int j = i; j < n; ++j)
        dp[i] = min(dp[i], k + trimmedLength[i][j] + dp[j + 1]);

    return dp[0];
  }
};
