class Solution {
 public:
  long long gridGame(vector<vector<int>>& grid) {
    const int n = grid[0].size();
    long long ans = LLONG_MAX;
    long long sumRow0 = accumulate(begin(grid[0]), end(grid[0]), 0LL);
    long long sumRow1 = 0;

    for (int i = 0; i < n; ++i) {
      sumRow0 -= grid[0][i];
      ans = min(ans, max(sumRow0, sumRow1));
      sumRow1 += grid[1][i];
    }

    return ans;
  }
};
