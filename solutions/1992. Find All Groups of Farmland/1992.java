class Solution {
  public int[][] findFarmland(int[][] land) {
    List<int[]> ans = new ArrayList<>();

    for (int i = 0; i < land.length; ++i)
      for (int j = 0; j < land[0].length; ++j)
        if (land[i][j] == 1) {
          int[] cell = new int[] {i, j};
          dfs(land, i, j, cell);
          ans.add(new int[] {i, j, cell[0], cell[1]});
        }

    return ans.stream().toArray(int[][] ::new);
  }

  private void dfs(int[][] land, int i, int j, int[] cell) {
    if (i < 0 || i == land.length || j < 0 || j == land[0].length)
      return;
    if (land[i][j] != 1)
      return;
    land[i][j] = 2; // Mark as visited.
    cell[0] = Math.max(cell[0], i);
    cell[1] = Math.max(cell[1], j);
    dfs(land, i + 1, j, cell);
    dfs(land, i, j + 1, cell);
  }
}
