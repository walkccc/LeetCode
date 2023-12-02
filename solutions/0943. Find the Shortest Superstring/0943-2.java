class Solution {
  public String shortestSuperstring(String[] A) {
    final int n = A.length;
    // cost[i][j] := the cost to append A[j] after A[i]
    int[][] cost = new int[n][n];
    // Pre-calculate the `cost` array to save time.
    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j) {
        cost[i][j] = getCost(A[i], A[j]);
        cost[j][i] = getCost(A[j], A[i]);
      }
    // dp[s][j] := the minimum cost to visit nodes of s ending in j, s is a
    // binary Value, e.g. dp[6][2] means the minimum cost to visit {1, 2} ending
    // in 2 (6 = 2^1 + 2^2)
    int[][] dp = new int[1 << n][n];
    Arrays.stream(dp).forEach(row -> Arrays.fill(row, Integer.MAX_VALUE / 2));
    // parent[s][j] := the parent of "nodes of s ending in j"
    int[][] parent = new int[1 << n][n];
    Arrays.stream(parent).forEach(row -> Arrays.fill(row, -1));

    for (int i = 0; i < n; ++i)
      dp[1 << i][i] = A[i].length();

    // Enumerate all the states ending in different nodes.
    for (int s = 1; s < (1 << n); ++s)
      for (int i = 0; i < n; ++i) {
        if ((s & (1 << i)) == 0)
          continue;
        for (int j = 0; j < n; ++j)
          if (dp[s - (1 << i)][j] + cost[j][i] < dp[s][i]) {
            dp[s][i] = dp[s - (1 << i)][j] + cost[j][i];
            parent[s][i] = j;
          }
      }

    String ans = "";
    int j = getLastNode(dp[(1 << n) - 1]);
    int s = (1 << n) - 1; // 2^0 + 2^1 + ... + 2^(n - 1)

    // Traverse back to build the string.
    while (s > 0) {
      final int i = parent[s][j];
      if (i == -1)
        ans = A[j] + ans;
      else
        ans = A[j].substring(A[j].length() - cost[i][j]) + ans;
      s -= 1 << j;
      j = i;
    }

    return ans;
  }

  // Returns the cost to append b after a.
  private int getCost(final String a, final String b) {
    int cost = b.length();
    final int minLength = Math.min(a.length(), b.length());
    for (int k = 1; k <= minLength; ++k)
      if (a.substring(a.length() - k).equals(b.substring(0, k)))
        cost = b.length() - k;
    return cost;
  }

  private int getLastNode(int[] row) {
    int minIndex = 0;
    for (int i = 1; i < row.length; ++i)
      if (row[i] < row[minIndex])
        minIndex = i;
    return minIndex;
  }
}
