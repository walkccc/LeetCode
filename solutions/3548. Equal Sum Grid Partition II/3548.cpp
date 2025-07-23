class Solution {
 public:
  bool canPartitionGrid(vector<vector<int>>& grid) {
    const long sum = accumulate(grid.begin(), grid.end(), 0L,
                                [](long acc, const vector<int>& row) {
      return acc + accumulate(row.begin(), row.end(), 0L);
    });
    return canPartition(grid, sum) || canPartition(reversed(grid), sum) ||
           canPartition(reversed(transposed(grid)), sum) ||
           canPartition(transposed(grid), sum);
  }

 private:
  bool canPartition(const vector<vector<int>>& grid, long sum) {
    long topSum = 0;
    unordered_set<int> seen;
    for (int i = 0; i < grid.size(); ++i) {
      topSum += accumulate(grid[i].begin(), grid[i].end(), 0L);
      const long botSum = sum - topSum;
      seen.insert(grid[i].begin(), grid[i].end());
      if (topSum - botSum == 0 || topSum - botSum == grid[0][0] ||
          topSum - botSum == grid[0].back() || topSum - botSum == grid[i][0])
        return true;
      if (grid[0].size() > 1 && i > 0 && seen.count(topSum - botSum))
        return true;
    }
    return false;
  }

  vector<vector<int>> transposed(const vector<vector<int>>& grid) {
    vector<vector<int>> res(grid[0].size(), vector<int>(grid.size()));
    for (int i = 0; i < grid.size(); ++i)
      for (int j = 0; j < grid[0].size(); ++j)
        res[j][i] = grid[i][j];
    return res;
  }

  vector<vector<int>> reversed(const vector<vector<int>>& grid) {
    return {grid.rbegin(), grid.rend()};
  }
};
