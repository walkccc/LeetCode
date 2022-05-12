class Solution {
 public:
  int countUnguarded(int m, int n, vector<vector<int>>& guards,
                     vector<vector<int>>& walls) {
    int ans = 0;
    vector<vector<char>> grid(m, vector<char>(n));
    vector<vector<char>> left(m, vector<char>(n));
    vector<vector<char>> right(m, vector<char>(n));
    vector<vector<char>> up(m, vector<char>(n));
    vector<vector<char>> down(m, vector<char>(n));

    for (const auto& guard : guards)
      grid[guard[0]][guard[1]] = 'G';

    for (const auto& wall : walls)
      grid[wall[0]][wall[1]] = 'W';

    for (int i = 0; i < m; ++i) {
      char lastCell = 0;
      for (int j = 0; j < n; ++j)
        recordOrFill(grid[i][j], lastCell, left[i][j]);
      lastCell = 0;
      for (int j = n - 1; j >= 0; --j)
        recordOrFill(grid[i][j], lastCell, right[i][j]);
    }

    for (int j = 0; j < n; ++j) {
      char lastCell = 0;
      for (int i = 0; i < m; ++i)
        recordOrFill(grid[i][j], lastCell, up[i][j]);
      lastCell = 0;
      for (int i = m - 1; i >= 0; --i)
        recordOrFill(grid[i][j], lastCell, down[i][j]);
    }

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (grid[i][j] == 0 && left[i][j] != 'G' && right[i][j] != 'G' &&
            up[i][j] != 'G' && down[i][j] != 'G')
          ++ans;

    return ans;
  }

 private:
  void recordOrFill(char currCell, char& lastCell, char& infoCell) {
    if (currCell == 'G' || currCell == 'W')
      lastCell = currCell;
    else
      infoCell = lastCell;
  }
};
