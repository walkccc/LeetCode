class Solution {
 public:
  // Same as 3176. Find the Maximum Length of a Good Subsequence I
  int maximumLength(vector<int>& nums, int k) {
    // dp[count][num] := the maximum length of a good subsequence with at most
    // `count` indices where seq[i] != seq[i + 1] and it ends in `num`.
    vector<unordered_map<int, int>> dp(k + 1);
    // maxLen[count] := the maximum length of a good subsequence with `count`
    // indices where seq[i] != seq[i + 1]
    vector<int> maxLen(k + 1);

    for (const int num : nums)
      for (int count = k; count >= 0; --count) {
        // Append `num` to the subsequence.
        ++dp[count][num];
        if (count > 0)
          dp[count][num] = max(dp[count][num], maxLen[count - 1] + 1);
        maxLen[count] = max(maxLen[count], dp[count][num]);
      }

    return maxLen[k];
  }
};
