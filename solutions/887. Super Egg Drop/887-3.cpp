class Solution {
 public:
  int superEggDrop(int k, int n) {
    int moves = 0;
    vector<vector<int>> dp(n + 1, vector<int>(k + 1));

    while (dp[moves][k] < n) {
      ++moves;
      for (int eggs = 1; eggs <= k; ++eggs)
        dp[moves][eggs] = dp[moves - 1][eggs - 1] + dp[moves - 1][eggs] + 1;
    }

    return moves;
  }
};
