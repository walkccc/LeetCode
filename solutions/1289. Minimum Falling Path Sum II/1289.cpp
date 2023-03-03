class Solution {
 public:
  int minFallingPathSum(vector<vector<int>>& grid) {
    const int n = grid.size();

    for (int i = 1; i < n; ++i) {
      const vector<pair<int, int>> twoMinNumAndIndexs =
          getTwoMinNumAndIndexs(grid[i - 1]);
      const auto& [firstMinNum, firstMinIndex] = twoMinNumAndIndexs[0];
      const auto& [secondMinNum, _] = twoMinNumAndIndexs[1];
      for (int j = 0; j < n; ++j)
        if (j == firstMinIndex)
          grid[i][j] += secondMinNum;
        else
          grid[i][j] += firstMinNum;
    }

    return *min_element(begin(grid.back()), end(grid.back()));
  }

 private:
  vector<pair<int, int>> getTwoMinNumAndIndexs(const vector<int>& A) {
    vector<pair<int, int>> numAndIndexs;

    for (int i = 0; i < A.size(); ++i)
      numAndIndexs.emplace_back(A[i], i);

    sort(begin(numAndIndexs), end(numAndIndexs));
    return {numAndIndexs[0], numAndIndexs[1]};
  }
};
