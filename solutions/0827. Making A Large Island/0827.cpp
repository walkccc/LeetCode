class Solution {
 public:
  int largestIsland(vector<vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();

    int ans = 0;
    vector<int> sizes{0, 0};  // sizes[i] := the size of i-th island

    // get the number of grid[i][j]
    auto getNum = [&](int i, int j) {
      if (i < 0 || i == m || j < 0 || j == n) return 0;  // invalid
      return grid[i][j];
    };

    function<int(int, int, int)> paint = [&](int i, int j, int color) {
      if (getNum(i, j) != 1) return 0;
      grid[i][j] = color;
      return paint(i + 1, j, color) + paint(i - 1, j, color) +
             paint(i, j + 1, color) + paint(i, j - 1, color) + 1;
    };

    // For each 1 in the grid, paint all connected 1 with the next available
    // color (2, 3, and so on). Also, remember the size of the island we just
    // painted with that color.
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (grid[i][j] == 1)
          sizes.push_back(paint(i, j, sizes.size()));  // paint 2, 3, ...

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (grid[i][j] == 0) {
          const unordered_set<int> nums{getNum(i + 1, j), getNum(i - 1, j),
                                        getNum(i, j + 1), getNum(i, j - 1)};
          ans = max(ans, getConnectedSize(nums, sizes) + 1);
        }

    return ans == 0 ? m * n : ans;
  }

 private:
  int getConnectedSize(const unordered_set<int>& nums,
                       const vector<int>& sizes) {
    int size = 0;
    for (const int num : nums)
      size += sizes[num];
    return size;
  }
};