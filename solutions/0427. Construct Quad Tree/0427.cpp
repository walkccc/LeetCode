class Solution {
 public:
  Node* construct(vector<vector<int>>& grid) {
    return helper(grid, 0, 0, grid.size());
  }

 private:
  Node* helper(const vector<vector<int>>& grid, int i, int j, int w) {
    if (allSame(grid, i, j, w))
      return new Node(grid[i][j], true);

    Node* node = new Node(true, false);
    node->topLeft = helper(grid, i, j, w / 2);
    node->topRight = helper(grid, i, j + w / 2, w / 2);
    node->bottomLeft = helper(grid, i + w / 2, j, w / 2);
    node->bottomRight = helper(grid, i + w / 2, j + w / 2, w / 2);
    return node;
  }

  bool allSame(const vector<vector<int>>& grid, int i, int j, int w) {
    return all_of(begin(grid) + i, begin(grid) + i + w,
                  [&](const vector<int>& row) {
      return all_of(begin(row) + j, begin(row) + j + w,
                    [&](int num) { return num == grid[i][j]; });
    });
  }
};
