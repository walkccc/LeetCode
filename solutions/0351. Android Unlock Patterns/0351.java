class Solution {
  public int numberOfPatterns(int m, int n) {
    int ans = 0;
    int[][] across = new int[10][10];
    boolean[] seen = new boolean[10];

    across[1][3] = across[3][1] = 2;
    across[1][7] = across[7][1] = 4;
    across[3][9] = across[9][3] = 6;
    across[7][9] = across[9][7] = 8;
    across[1][9] = across[9][1] = across[2][8] = across[8][2] = across[3][7] = across[7][3] =
        across[4][6] = across[6][4] = 5;

    ans += dfs(m, n, 1, 1, seen, across) * 4; // 1, 3, 7, 9 are symmetric
    ans += dfs(m, n, 2, 1, seen, across) * 4; // 2, 4, 6, 8 are symmetric
    ans += dfs(m, n, 5, 1, seen, across);     // 5
    return ans;
  }

  private int dfs(int m, int n, int u, int level, boolean[] seen, int[][] across) {
    if (level > n)
      return 0;

    seen[u] = true;
    int ans = level >= m;

    for (int v = 1; v <= 9; ++v) {
      if (v == u || seen[v])
        continue;
      final int acrossed = across[u][v];
      if (acrossed == 0 || seen[acrossed])
        ans += dfs(m, n, v, level + 1, seen, across);
    }

    seen[u] = false;
    return ans;
  }
}
