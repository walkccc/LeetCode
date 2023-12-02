class Solution {
 public:
  bool isThereAPath(vector<vector<int>>& grid) {
    m = grid.size();
    n = grid[0].size();
    // Map negative (the number of 0s - the number of 1s) to non-negative one.
    cells = m + n - 1;
    if (cells & 1)
      return false;
    // dp[i][j][cells + k] := 1 if there's a path to grid[i][j] s.t.
    // k = (the number of 0s - the number of 1s).
    dp.resize(m, vector<vector<int>>(n, vector<int>(cells * 2 + 1, -1)));
    return isThereAPath(grid, 0, 0, 0);
  }

 private:
  int m;
  int n;
  int cells;
  vector<vector<vector<int>>> dp;

  bool isThereAPath(const vector<vector<int>>& grid, int i, int j, int sum) {
    if (i == m || j == n)
      return false;
    sum += grid[i][j] == 0 ? 1 : -1;
    if (i == m - 1 && j == n - 1)
      return sum == 0;
    int& ans = dp[i][j][cells + sum];
    if (ans != -1)
      return ans == 1 ? true : false;
    ans =
        isThereAPath(grid, i + 1, j, sum) || isThereAPath(grid, i, j + 1, sum);
    return ans == 1 ? true : false;
  }
};
