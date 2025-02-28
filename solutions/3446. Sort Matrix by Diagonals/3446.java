class Solution {
  public int[][] sortMatrix(int[][] grid) {
    final int n = grid.length;
    int[][] ans = new int[n][n];
    Map<Integer, List<Integer>> diag = new HashMap<>();

    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) {
        final int key = i - j;
        diag.putIfAbsent(key, new ArrayList<>());
        diag.get(key).add(grid[i][j]);
      }

    for (Map.Entry<Integer, List<Integer>> entry : diag.entrySet()) {
      List<Integer> values = entry.getValue();
      if (entry.getKey() < 0)
        Collections.sort(values, Collections.reverseOrder());
      else
        Collections.sort(values);
    }

    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) {
        final int key = i - j;
        ans[i][j] = diag.get(key).remove(diag.get(key).size() - 1);
      }

    return ans;
  }
}
