class Solution {
 public:
  long long maxScore(vector<int>& a, vector<int>& b) {
    // dp[i] := the maximum score of a[0..i]
    vector<long> dp(4, LONG_MIN / 2);

    for (const long num : b)
      for (int i = 3; i >= 0; --i)
        // Skip `num` or pair a[i] with `num`.
        dp[i] = max(dp[i], (i > 0 ? dp[i - 1] : 0) + a[i] * num);

    return dp[3];
  }
};
