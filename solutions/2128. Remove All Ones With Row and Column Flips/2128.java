class Solution {
  public boolean removeOnes(int[][] grid) {
    int[] revRow = getRevRow(grid[0]);
    return Arrays.stream(grid).allMatch(
        row -> Arrays.equals(row, grid[0]) || Arrays.equals(row, revRow));
  }

  private int[] getRevRow(int[] row) {
    int[] revRow = new int[row.length];
    for (int i = 0; i < row.length; ++i)
      revRow[i] = row[i] ^ 1;
    return revRow;
  }
}
