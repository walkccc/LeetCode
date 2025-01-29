class Solution {
  public int selfDivisiblePermutationCount(int n) {
    int s = 1 << n;
    int[][] dp = new int[n + 1][s];
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
      for (int state = 0; state < (s); state++) {
        for (int d = 1; d <= n; d++) {
          if (gcd(d, i) != 1) {
            continue;
          }
          if (((state >> (d - 1)) & 1) == 0) {
            continue;
          }
          dp[i][state] += dp[i - 1][state - (1 << (d - 1))];
        }
      }
    }

    return dp[n][(s) - 1];
  }

  private int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
  }
}
