class Solution {
 public:
  int removeBoxes(vector<int>& boxes) {
    const int n = boxes.size();

    // dp[i][j][k] := max score of boxes[i..j]
    // if k boxes having same color as boxes[j]
    vector<vector<vector<int>>> memo(n, vector<vector<int>>(n, vector<int>(n)));

    function<int(int, int, int)> dp = [&](int i, int j, int k) {
      if (i > j) return 0;
      if (memo[i][j][k]) return memo[i][j][k];

      memo[i][j][k] = dp(i, j - 1, 0) + (k + 1) * (k + 1);

      for (int p = i; p < j; ++p)
        if (boxes[p] == boxes[j])
          memo[i][j][k] =
              max(memo[i][j][k], dp(i, p, k + 1) + dp(p + 1, j - 1, 0));

      return memo[i][j][k];
    };

    return dp(0, n - 1, 0);
  }
};