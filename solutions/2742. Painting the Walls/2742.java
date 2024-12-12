class Solution {
  public int paintWalls(int[] cost, int[] time) {
    final int n = cost.length;
    int[][] mem = new int[n][n + 1];
    return paintWalls(cost, time, 0, time.length, mem);
  }

  private static final int kMax = 500_000_000;

  // Returns the minimum cost to paint j walls by painters[i..n).
  private int paintWalls(int[] cost, int[] time, int i, int walls, int[][] mem) {
    if (walls <= 0)
      return 0;
    if (i == cost.length)
      return kMax;
    if (mem[i][walls] > 0)
      return mem[i][walls];
    final int pick = cost[i] + paintWalls(cost, time, i + 1, walls - time[i] - 1, mem);
    final int skip = paintWalls(cost, time, i + 1, walls, mem);
    return mem[i][walls] = Math.min(pick, skip);
  }
}
