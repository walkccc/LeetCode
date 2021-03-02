class Solution {
  public int superEggDrop(int K, int N) {
    int moves = 0;
    int[][] dp = new int[N + 1][K + 1];

    while (dp[moves][K] < N) {
      ++moves;
      for (int eggs = 1; eggs <= K; ++eggs)
        dp[moves][eggs] = dp[moves - 1][eggs - 1] + dp[moves - 1][eggs] + 1;
    }

    return moves;
  }
}
