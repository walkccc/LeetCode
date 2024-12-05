class Solution {
 public:
  vector<int> maximumSubarrayXor(vector<int>& nums,
                                 vector<vector<int>>& queries) {
    const int n = nums.size();
    vector<int> ans;
    // xors[i][j] := the XOR score of nums[i..j]
    vector<vector<int>> xors(n, vector<int>(n));
    // dp[i][j] := the maximum XOR score of nums[i..j]
    vector<vector<int>> dp(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
      xors[i][i] = nums[i];
      dp[i][i] = nums[i];
    }

    for (int d = 1; d < n; ++d)
      for (int i = 0; i + d < n; ++i) {
        const int j = i + d;
        xors[i][j] = xors[i][j - 1] ^ xors[i + 1][j];
        dp[i][j] = max({xors[i][j], dp[i][j - 1], dp[i + 1][j]});
      }

    for (const vector<int>& query : queries) {
      const int l = query[0];
      const int r = query[1];
      ans.push_back(dp[l][r]);
    }

    return ans;
  }
};
