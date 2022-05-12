class Solution {
  public double soupServings(int N) {
    return N >= 4800 ? 1.0 : dfs((N + 24) / 25, (N + 24) / 25);
  }

  private double[][] memo = new double[4800 / 25][4800 / 25];

  private double dfs(int a, int b) {
    if (a <= 0 && b <= 0)
      return 0.5;
    if (a <= 0)
      return 1.0;
    if (b <= 0)
      return 0.0;
    if (memo[a][b] > 0)
      return memo[a][b];
    return memo[a][b] = 0.25 * (dfs(a - 4, b) +
                                dfs(a - 3, b - 1) +
                                dfs(a - 2, b - 2) +
                                dfs(a - 1, b - 3));
  }
}
