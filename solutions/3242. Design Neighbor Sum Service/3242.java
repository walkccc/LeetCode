class neighborSum {
  public neighborSum(int[][] grid) {
    this.n = grid.length;
    this.grid = grid;
    this.numToPos = new Pair[n * n];
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        numToPos[grid[i][j]] = new Pair<>(i, j);
  }

  public int adjacentSum(int value) {
    final int i = numToPos[value].getKey();
    final int j = numToPos[value].getValue();
    int sum = 0;
    int[][] directions = {{i - 1, j}, {i + 1, j}, {i, j - 1}, {i, j + 1}};
    for (int[] dir : directions) {
      final int x = dir[0];
      final int y = dir[1];
      if (x >= 0 && x < n && y >= 0 && y < n)
        sum += grid[x][y];
    }
    return sum;
  }

  public int diagonalSum(int value) {
    final int i = numToPos[value].getKey();
    final int j = numToPos[value].getValue();
    int sum = 0;
    int[][] directions = {{i - 1, j - 1}, {i - 1, j + 1}, {i + 1, j - 1}, {i + 1, j + 1}};
    for (int[] dir : directions) {
      final int x = dir[0];
      final int y = dir[1];
      if (x >= 0 && x < n && y >= 0 && y < n)
        sum += grid[x][y];
    }
    return sum;
  }

  private int n;
  private int[][] grid;
  private Pair<Integer, Integer>[] numToPos;
}
