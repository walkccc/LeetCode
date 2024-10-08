class Solution {
  public int minimumChanges(String s, int k) {
    final int n = s.length();
    // factors[i] := factors of i
    List<Integer>[] factors = getFactors(n);
    // cost[i][j] := changes to make s[i..j] a semi-palindrome
    int[][] cost = getCost(s, n, factors);
    // dp[i][j] := the minimum changes to split s[i:] into j valid parts
    int[][] dp = new int[n + 1][k + 1];

    Arrays.stream(dp).forEach(A -> Arrays.fill(A, n));
    dp[n][0] = 0;

    for (int i = n - 1; i >= 0; --i)
      for (int j = 1; j <= k; ++j)
        for (int l = i + 1; l < n; ++l)
          dp[i][j] = Math.min(dp[i][j], dp[l + 1][j - 1] + cost[i][l]);

    return dp[0][k];
  }

  private List<Integer>[] getFactors(int n) {
    List<Integer>[] factors = new List[n + 1];
    for (int i = 1; i <= n; ++i)
      factors[i] = new ArrayList<>(List.of(1));
    for (int d = 2; d < n; ++d)
      for (int i = d * 2; i <= n; i += d)
        factors[i].add(d);
    return factors;
  }

  private int[][] getCost(final String s, int n, List<Integer>[] factors) {
    int[][] cost = new int[n][n];
    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j) {
        final int length = j - i + 1;
        int minCost = length;
        for (final int d : factors[length])
          minCost = Math.min(minCost, getCost(s, i, j, d));
        cost[i][j] = minCost;
      }
    return cost;
  }

  // Returns the cost to make s[i..j] a semi-palindrome of `d`.
  private int getCost(final String s, int i, int j, int d) {
    int cost = 0;
    for (int offset = 0; offset < d; ++offset) {
      int l = i + offset;
      int r = j - d + 1 + offset;
      while (l < r) {
        if (s.charAt(l) != s.charAt(r))
          ++cost;
        l += d;
        r -= d;
      }
    }
    return cost;
  }
}
