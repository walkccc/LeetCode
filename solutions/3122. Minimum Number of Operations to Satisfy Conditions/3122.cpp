class Solution {
 public:
  int minimumOperations(vector<vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    vector<vector<int>> count(n, vector<int>(10));

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        ++count[j][grid[i][j]];

    vector<vector<int>> mem(n, vector<int>(10, -1));
    return minimumOperations(count, 0, 0, m, mem);
  }

 private:
  // Returns the number of minimum operations needed to make grid[:][j..n)
  // satisfy the conditions, where the (j - 1)-th column is filled with `prev`.
  int minimumOperations(const vector<vector<int>>& count, int j, int prev,
                        int m, vector<vector<int>>& mem) {
    if (j == count.size())
      return 0;
    if (mem[j][prev] != -1)
      return mem[j][prev];

    int res = INT_MAX;

    for (int num = 0; num < 10; ++num)
      if (j == 0 || num != prev)
        res = min(res, m - count[j][num] +
                           minimumOperations(count, j + 1, num, m, mem));

    return mem[j][prev] = res;
  }
};
