class Solution {
  public int maximumInvitations(int[][] grid) {
    final int m = grid.length;
    final int n = grid[0].length;
    int ans = 0;
    int[] mate = new int[n]; // girl's mate

    Arrays.fill(mate, -1);

    for (int i = 0; i < m; ++i)
      if (canInvite(grid, i, new boolean[n], mate))
        ++ans;

    return ans;
  }

  private boolean canInvite(int[][] grid, int i, boolean[] seen, int[] mate) {
    // boy i ask each girl
    for (int j = 0; j < seen.length; ++j) {
      if (grid[i][j] == 0 || seen[j])
        continue;
      seen[j] = true;
      if (mate[j] == -1 || canInvite(grid, mate[j], seen, mate)) {
        mate[j] = i; // match girl j w/ boy i
        return true;
      }
    }

    return false;
  }
}
