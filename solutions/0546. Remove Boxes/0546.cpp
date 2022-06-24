class Solution {
 public:
  int removeBoxes(vector<int>& boxes) {
    const int n = boxes.size();
    // dp[i][j][k] := max score of boxes[i..j] if k boxes eqaul to boxes[j]
    dp.resize(n, vector<vector<int>>(n, vector<int>(n)));
    return removeBoxes(boxes, 0, n - 1, 0);
  }

 private:
  vector<vector<vector<int>>> dp;

  int removeBoxes(const vector<int>& boxes, int i, int j, int k) {
    if (i > j)
      return 0;
    if (dp[i][j][k])
      return dp[i][j][k];

    int r = j;
    int sameBoxes = k + 1;
    while (r > 0 && boxes[r - 1] == boxes[r]) {
      --r;
      ++sameBoxes;
    }
    dp[i][j][k] = removeBoxes(boxes, i, r - 1, 0) + sameBoxes * sameBoxes;

    for (int p = i; p < r; ++p)
      if (boxes[p] == boxes[r])
        dp[i][j][k] = max(dp[i][j][k], removeBoxes(boxes, i, p, sameBoxes) +
                                           removeBoxes(boxes, p + 1, r - 1, 0));

    return dp[i][j][k];
  }
};
