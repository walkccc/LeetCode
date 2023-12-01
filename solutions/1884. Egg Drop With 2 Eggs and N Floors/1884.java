class Solution {
  public int twoEggDrop(int n) {
    return superEggDrop(2, n);
  }

  private int[][] dp;

  private int superEggDrop(int k, int N) {
    // dp[k][n] := the minimum number of moves to know F with k eggs and n floors
    dp = new int[k + 1][N + 1];
    Arrays.stream(dp).forEach(A -> Arrays.fill(A, -1));
    return drop(k, N);
  }

  private int drop(int k, int n) {
    if (k == 0) // no eggs -> done
      return 0;
    if (k == 1) // one egg -> drop from 1-th floor to n-th floor
      return n;
    if (n == 0) // no floor -> done
      return 0;
    if (n == 1) // one floor -> drop from that floor
      return 1;
    if (dp[k][n] != -1)
      return dp[k][n];

    //   broken[i] := drop(k - 1, i - 1) is increasing with i
    // unbroken[i] := drop(k,     n - i) is decreasing with i
    // dp[k][n] := 1 + min(max(broken[i], unbroken[i])), 1 <= i <= n
    // Find the first index i s.t broken[i] >= unbroken[i],
    // which minimizes max(broken[i], unbroken[i])

    int l = 1;
    int r = n + 1;

    while (l < r) {
      final int m = (l + r) / 2;
      final int broken = drop(k - 1, m - 1);
      final int unbroken = drop(k, n - m);
      if (broken >= unbroken)
        r = m;
      else
        l = m + 1;
    }

    return dp[k][n] = 1 + drop(k - 1, l - 1);
  }
}
