class Solution {
 public:
  int minimizeTheDifference(vector<vector<int>>& mat, int target) {
    const int minSum = getMinSum(mat);
    if (minSum >= target)  // No need to consider any larger combination.
      return minSum - target;

    const int maxSum = getMaxSum(mat);
    dp.resize(mat.size(), vector<int>(maxSum + 1, -1));
    return minimizeTheDifference(mat, 0, 0, target);
  }

 private:
  vector<vector<int>> dp;

  int minimizeTheDifference(const vector<vector<int>>& mat, int i, int sum,
                            int target) {
    if (i == mat.size())
      return abs(sum - target);
    if (dp[i][sum] != -1)
      return dp[i][sum];
    int ans = INT_MAX;
    for (const int num : mat[i])
      ans = min(ans, minimizeTheDifference(mat, i + 1, sum + num, target));
    return dp[i][sum] = ans;
  }

  int getMinSum(const vector<vector<int>>& mat) {
    return accumulate(mat.begin(), mat.end(), 0,
                      [](int subtotal, const vector<int>& row) {
      return subtotal + ranges::min(row);
    });
  }

  int getMaxSum(const vector<vector<int>>& mat) {
    return accumulate(mat.begin(), mat.end(), 0,
                      [](int subtotal, const vector<int>& row) {
      return subtotal + ranges::max(row);
    });
  }
};
