class Solution {
 public:
  // Similar to 53. Maximum Subarray
  int maximumSum(vector<int>& arr) {
    // dp[0][i] := the maximum sum subarray ending in i (no deletion)
    // dp[1][i] := the maximum sum subarray ending in i (at most 1 deletion)
    vector<vector<int>> dp(2, vector<int>(arr.size()));

    dp[0][0] = arr[0];
    dp[1][0] = arr[0];
    for (int i = 1; i < arr.size(); ++i) {
      dp[0][i] = max(arr[i], dp[0][i - 1] + arr[i]);
      dp[1][i] =
          max({arr[i], dp[1][i - 1] + arr[i], dp[0][i - 1] /*delete arr[i]*/});
    }

    return ranges::max(dp[1]);
  }
};
