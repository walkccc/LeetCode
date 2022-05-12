class Solution {
 public:
  bool removeOnes(vector<vector<int>>& grid) {
    const auto revRow = getRevRow(grid[0]);
    return all_of(begin(grid), end(grid), [&](const auto& row) {
      return row == grid[0] || row == revRow;
    });
  }

 private:
  vector<int> getRevRow(vector<int>& row) {
    vector<int> revRow;
    for (const int a : row)
      revRow.push_back(a ^ 1);
    return revRow;
  }
};
