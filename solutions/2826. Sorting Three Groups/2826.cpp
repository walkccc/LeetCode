class Solution {
 public:
  int minimumOperations(vector<int>& nums) {
    // dp[i] := the longest non-decreasing subsequence so far with numbers in
    // [1..i]
    vector<int> dp(4);

    for (const int num : nums) {
      ++dp[num];
      dp[2] = max(dp[2], dp[1]);
      dp[3] = max(dp[3], dp[2]);
    }

    return nums.size() - dp[3];
  }
};
