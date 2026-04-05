class Solution {
 public:
  vector<vector<int>> specialGrid(int n) {
    const int sz = 1 << n;
    int count = 0;
    vector<vector<int>> grid(sz, vector<int>(sz));
    fill(grid, 0, sz, 0, sz, count);
    return grid;
  }

  void fill(vector<vector<int>>& grid, int x1, int x2, int y1, int y2,
            int& count) {
    if (x2 - x1 == 1) {
      grid[x1][y1] = count++;
      return;
    }
    const int midRow = (x1 + x2) / 2;
    const int midCol = (y1 + y2) / 2;
    fill(grid, x1, midRow, midCol, y2, count);
    fill(grid, midRow, x2, midCol, y2, count);
    fill(grid, midRow, x2, y1, midCol, count);
    fill(grid, x1, midRow, y1, midCol, count);
  }
};
