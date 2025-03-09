class Solution {
  public List<List<Integer>> shiftGrid(int[][] grid, int k) {
    final int m = grid.length;
    final int n = grid[0].length;
    List<List<Integer>> ans = new ArrayList<>();
    int[][] arr = new int[m][n];

    k %= m * n;

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        final int index = (i * n + j + k) % (m * n);
        final int x = index / n;
        final int y = index % n;
        arr[x][y] = grid[i][j];
      }

    for (int[] row : arr)
      ans.add(Arrays.stream(row).boxed().collect(Collectors.toList()));

    return ans;
  }
}
