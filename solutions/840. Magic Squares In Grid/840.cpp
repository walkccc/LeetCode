class Solution {
 public:
  int numMagicSquaresInside(vector<vector<int>>& grid) {
    int ans = 0;

    for (int i = 0; i + 2 < grid.size(); ++i)
      for (int j = 0; j + 2 < grid[0].size(); ++j)
        if (grid[i][j] % 2 == 0 && grid[i + 1][j + 1] == 5)
          ans += isMagic(grid, i, j);

    return ans;
  }

 private:
  int isMagic(const vector<vector<int>>& grid, int i, int j) {
    string s;

    for (const int num : {0, 1, 2, 5, 8, 7, 6, 3})
      s += to_string(grid[i + num / 3][j + num % 3]);

    return string("4381672943816729").find(s) != string::npos ||
           string("9276183492761834").find(s) != string::npos;
  }
};
