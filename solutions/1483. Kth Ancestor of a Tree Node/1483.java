class TreeAncestor {
  public TreeAncestor(int n, int[] parent) {
    this.maxLevel = 32 - Integer.numberOfLeadingZeros(n);
    this.dp = new int[n][maxLevel];

    // Node i's 2^0 ancestor is its direct parent.
    for (int i = 0; i < n; ++i)
      dp[i][0] = parent[i];

    for (int j = 1; j < maxLevel; ++j)
      for (int i = 0; i < n; ++i)
        if (dp[i][j - 1] == -1) // There's no such ancestor.
          dp[i][j] = -1;
        else // A(i, 2^j) = A(A(i, 2^{j - 1}), 2^{j - 1})
          dp[i][j] = dp[dp[i][j - 1]][j - 1];
  }

  public int getKthAncestor(int node, int k) {
    for (int j = 0; j < maxLevel && node != -1; ++j)
      if ((k >> j & 1) == 1)
        node = dp[node][j];
    return node;
  }

  private final int maxLevel;
  private int[][] dp; // dp[i][j] := node i's 2^j-th ancestor
}
