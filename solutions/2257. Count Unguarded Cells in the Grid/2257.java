class Solution {
  public int countUnguarded(int m, int n, int[][] guards, int[][] walls) {
    int ans = 0;
    char[][] grid = new char[m][n];
    char[][] left = new char[m][n];
    char[][] right = new char[m][n];
    char[][] up = new char[m][n];
    char[][] down = new char[m][n];

    for (int[] guard : guards)
      grid[guard[0]][guard[1]] = 'G';

    for (int[] wall : walls)
      grid[wall[0]][wall[1]] = 'W';

    for (int i = 0; i < m; ++i) {
      char lastCell = 0;
      for (int j = 0; j < n; ++j)
        if (grid[i][j] == 'G' || grid[i][j] == 'W')
          lastCell = grid[i][j];
        else
          left[i][j] = lastCell;
      lastCell = 0;
      for (int j = n - 1; j >= 0; --j)
        if (grid[i][j] == 'G' || grid[i][j] == 'W')
          lastCell = grid[i][j];
        else
          right[i][j] = lastCell;
    }

    for (int j = 0; j < n; ++j) {
      char lastCell = 0;
      for (int i = 0; i < m; ++i)
        if (grid[i][j] == 'G' || grid[i][j] == 'W')
          lastCell = grid[i][j];
        else
          up[i][j] = lastCell;
      lastCell = 0;
      for (int i = m - 1; i >= 0; --i)
        if (grid[i][j] == 'G' || grid[i][j] == 'W')
          lastCell = grid[i][j];
        else
          down[i][j] = lastCell;
    }

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (grid[i][j] == 0 && left[i][j] != 'G' && right[i][j] != 'G' && up[i][j] != 'G' &&
            down[i][j] != 'G')
          ++ans;

    return ans;
  }
}
