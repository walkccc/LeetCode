class Solution {
  public int maximumInvitations(int[][] grid) {
    final int m = grid.length;
    final int n = grid[0].length;
    int ans = 0;
    int[] mates = new int[n]; // mates[i] := the i-th girl's mate

    Arrays.fill(mates, -1);

    for (int i = 0; i < m; ++i)
      if (canInvite(grid, i, new boolean[n], mates))
        ++ans;

    return ans;
  }

  // Returns true if the i-th boy can make an invitation.
  private boolean canInvite(int[][] grid, int i, boolean[] seen, int[] mates) {
    // The i-th boy asks each girl.
    for (int j = 0; j < seen.length; ++j) {
      if (grid[i][j] == 0 || seen[j])
        continue;
      seen[j] = true;
      if (mates[j] == -1 || canInvite(grid, mates[j], seen, mates)) {
        mates[j] = i; // Match the j-th girl with i-th boy.
        return true;
      }
    }

    return false;
  }
}
