class Solution {
 public:
  int minTotalDistance(vector<vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    vector<int> I;  // i indices s.t. grid[i][j] == 1
    vector<int> J;  // j indices s.t. grid[i][j] == 1

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (grid[i][j])
          I.push_back(i);

    for (int j = 0; j < n; ++j)
      for (int i = 0; i < m; ++i)
        if (grid[i][j])
          J.push_back(j);

    // sum(i - median(I)) + sum(j - median(J))
    return minTotalDistance(I) + minTotalDistance(J);
  }

 private:
  int minTotalDistance(const vector<int>& grid) {
    int sum = 0;
    int i = 0;
    int j = grid.size() - 1;
    while (i < j)
      sum += grid[j--] - grid[i++];
    return sum;
  }
};
