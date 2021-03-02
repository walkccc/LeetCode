class Solution {
 public:
  int superEggDrop(int K, int N) {
    int moves = 0;
    vector<vector<int>> dp(N + 1, vector<int>(K + 1));

    while (dp[moves][K] < N) {
      ++moves;
      for (int eggs = 1; eggs <= K; ++eggs)
        dp[moves][eggs] = dp[moves - 1][eggs - 1] + dp[moves - 1][eggs] + 1;
    }

    return moves;
  }
};
