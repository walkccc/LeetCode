class Solution {
  public int minTotalDistance(int[][] grid) {
    final int m = grid.length;
    final int n = grid[0].length;
    List<Integer> I = new ArrayList<>(); // i indices s.t. grid[i][j] == 1
    List<Integer> J = new ArrayList<>(); // j indices s.t. grid[i][j] == 1

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (grid[i][j] == 1)
          I.add(i);

    for (int j = 0; j < n; ++j)
      for (int i = 0; i < m; ++i)
        if (grid[i][j] == 1)
          J.add(j);

    // sum(i - median(I)) + sum(j - median(J))
    return minTotalDistance(I) + minTotalDistance(J);
  }

  private int minTotalDistance(List<Integer> grid) {
    int sum = 0;
    int i = 0;
    int j = grid.size() - 1;

    while (i < j)
      sum += grid.get(j--) - grid.get(i++);

    return sum;
  }
}
