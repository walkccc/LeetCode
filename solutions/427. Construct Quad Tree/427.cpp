class Solution {
 public:
  Node* construct(vector<vector<int>>& grid) {
    return helper(grid, 0, 0, grid.size());
  }

 private:
  Node* helper(const vector<vector<int>>& grid, int i, int j, int w) {
    if (allSame(grid, i, j, w))
      return new Node(grid[i][j] == 1, /*isLeaft=*/true);
    const int half = w / 2;
    return new Node(/*val=*/true, /*isLeaf=*/false,
                    /*topLeft=*/helper(grid, i, j, half),
                    /*topRight=*/helper(grid, i, j + half, half),
                    /*bottomLeft=*/helper(grid, i + half, j, half),
                    /*bottomRight=*/helper(grid, i + half, j + half, half));
  }

  bool allSame(const vector<vector<int>>& grid, int i, int j, int w) {
    return all_of(grid.begin() + i, grid.begin() + i + w,
                  [&](const vector<int>& row) {
      return all_of(row.begin() + j, row.begin() + j + w,
                    [&](int num) { return num == grid[i][j]; });
    });
  }
};
