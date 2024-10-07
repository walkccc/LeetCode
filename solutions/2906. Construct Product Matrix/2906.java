class Solution {
  public int[][] constructProductMatrix(int[][] grid) {
    final int kMod = 12345;
    final int m = grid.length;
    final int n = grid[0].length;
    int[][] ans = new int[m][n];
    List<Integer> prefix = new ArrayList<>(List.of(1));
    int suffix = 1;

    for (int[] row : grid)
      for (int cell : row)
        prefix.add((int) ((long) prefix.get(prefix.size() - 1) * cell % kMod));

    for (int i = m - 1; i >= 0; i--)
      for (int j = n - 1; j >= 0; j--) {
        ans[i][j] = (int) ((long) prefix.get(i * n + j) * suffix % kMod);
        suffix = (int) ((long) suffix * grid[i][j] % kMod);
      }

    return ans;
  }
}
