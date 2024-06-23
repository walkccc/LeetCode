class Solution {
 public:
  int findChampion(vector<vector<int>>& grid) {
    for (int i = 0; i < grid.size(); ++i)
      if (accumulate(grid[i].begin(), grid[i].end(), 0) == grid.size() - 1)
        return i;
    return -1;
  }
};
