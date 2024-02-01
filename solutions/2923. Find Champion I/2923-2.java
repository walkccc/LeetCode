class Solution {
  public int findChampion(int[][] grid) {
    for (int i = 0; i < grid.length; ++i)
      if (Arrays.stream(grid[i]).sum() == grid.length - 1)
        return i;
    return -1;
  }
}
