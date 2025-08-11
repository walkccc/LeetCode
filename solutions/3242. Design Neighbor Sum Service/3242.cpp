class neighborSum {
 public:
  neighborSum(vector<vector<int>>& grid)
      : n(grid.size()), grid(grid), numToPos(n * n) {
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        numToPos[grid[i][j]] = {i, j};
  }

  int adjacentSum(int value) {
    const auto& [i, j] = numToPos[value];
    int sum = 0;
    for (const auto& [x, y] :
         vector<pair<int, int>>{{i - 1, j}, {i + 1, j}, {i, j - 1}, {i, j + 1}})
      if (x >= 0 && x < n && y >= 0 && y < n)
        sum += grid[x][y];
    return sum;
  }

  int diagonalSum(int value) {
    const auto& [i, j] = numToPos[value];
    int sum = 0;
    for (const auto& [x, y] : vector<pair<int, int>>{
             {i - 1, j - 1}, {i - 1, j + 1}, {i + 1, j - 1}, {i + 1, j + 1}})
      if (x >= 0 && x < n && y >= 0 && y < n)
        sum += grid[x][y];
    return sum;
  }

 private:
  const int n;
  vector<vector<int>> grid;
  vector<pair<int, int>> numToPos;
};
