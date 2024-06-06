class Solution {
  public boolean canMakeSquare(char[][] grid) {
    for (int i = 0; i < 2; ++i)
      for (int j = 0; j < 2; ++j) {
        int black = 0;
        int white = 0;
        for (int x = 0; x < 2; ++x)
          for (int y = 0; y < 2; ++y)
            if (grid[i + x][j + y] == 'B')
              ++black;
            else
              ++white;
        if (black >= 3 || white >= 3)
          return true;
      }
    return false;
  }
}
