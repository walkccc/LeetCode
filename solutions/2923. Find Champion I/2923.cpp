class Solution {
 public:
  int findChampion(vector<vector<int>>& grid) {
    const int n = grid.size();
    int ans = -1;
    int count = 0;
    vector<int> inDegrees(n);

    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) {
        if (i == j)
          continue;
        grid[i][j] == 1 ? ++inDegrees[j] : ++inDegrees[i];
      }

    for (int i = 0; i < n; ++i)
      if (inDegrees[i] == 0) {
        ++count;
        ans = i;
      }

    return count > 1 ? -1 : ans;
  }
};
