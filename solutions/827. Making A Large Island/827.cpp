class Solution {
 public:
  int largestIsland(vector<vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    int maxSize = 0;
    // sizes[i] := the size of the i-th connected component (starting from 2)
    vector<int> sizes{0, 0};

    // For each 1 in the grid, paint all the connected 1s with the next
    // available color (2, 3, and so on). Also, remember the size of the island
    // we just painted with that color.
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (grid[i][j] == 1)
          sizes.push_back(paint(grid, i, j, sizes.size()));  // Paint 2, 3, ...

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (grid[i][j] == 0) {
          const unordered_set<int> neighborIds{
              getId(grid, i + 1, j), getId(grid, i - 1, j),
              getId(grid, i, j + 1), getId(grid, i, j - 1)};
          maxSize = max(maxSize, 1 + getSize(neighborIds, sizes));
        }

    return maxSize == 0 ? m * n : maxSize;
  }

 private:
  int paint(vector<vector<int>>& grid, int i, int j, int id) {
    if (i < 0 || i == grid.size() || j < 0 || j == grid[0].size())
      return 0;
    if (grid[i][j] != 1)
      return 0;
    grid[i][j] = id;  // grid[i][j] is part of the id-th connected component.
    return 1 + paint(grid, i + 1, j, id) + paint(grid, i - 1, j, id) +
           paint(grid, i, j + 1, id) + paint(grid, i, j - 1, id);
  }

  // Gets the id of grid[i][j] and returns 0 if it's out-of-bounds.
  int getId(const vector<vector<int>>& grid, int i, int j) {
    if (i < 0 || i == grid.size() || j < 0 || j == grid[0].size())
      return 0;  // Invalid
    return grid[i][j];
  }

  int getSize(const unordered_set<int>& neighborIds, const vector<int>& sizes) {
    int size = 0;
    for (const int neighborId : neighborIds)
      size += sizes[neighborId];
    return size;
  }
};
