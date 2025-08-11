class Solution {
 public:
  vector<long long> countBlackBlocks(int m, int n,
                                     vector<vector<int>>& coordinates) {
    vector<long long> ans(5);
    // count[i * n + j] := the number of black cells in
    // (i - 1, j - 1), (i - 1, j), (i, j - 1), (i, j)
    unordered_map<long, int> count;

    for (const vector<int>& coordinate : coordinates) {
      const int x = coordinate[0];
      const int y = coordinate[1];
      for (long i = x; i < x + 2; ++i)
        for (long j = y; j < y + 2; ++j)
          // 2 x 2 submatrix with right-bottom conner being (i, j) contains the
          // current black cell (x, y).
          if (i - 1 >= 0 && i < m && j - 1 >= 0 && j < n)
            ++count[i * n + j];
    }

    for (const auto& [_, freq] : count)
      ++ans[freq];

    ans[0] = (m - 1L) * (n - 1) - accumulate(ans.begin(), ans.end(), 0L);
    return ans;
  }
};
