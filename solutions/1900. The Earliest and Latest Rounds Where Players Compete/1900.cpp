class Solution {
 public:
  vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
    dp.resize(n + 1, vector<vector<P>>(n + 1, vector<P>(n + 1)));
    const auto [a, b] = solve(firstPlayer, n - secondPlayer + 1, n);
    return {a, b};
  }

 private:
  typedef pair<int, int> P;
  // dp[i][j][k] := (earliest, latest) pair w/ firstPlayer is i-th player from
  // front, secondPlayer is j-th player from end, and there're k people
  vector<vector<vector<P>>> dp;

  P solve(int l, int r, int k) {
    if (l == r)
      return {1, 1};
    if (l > r)
      swap(l, r);
    if (dp[l][r][k] != pair<int, int>(0, 0))
      return dp[l][r][k];

    int a = INT_MAX;
    int b = INT_MIN;

    // enumerate all possible positions
    for (int i = 1; i <= l; ++i)
      for (int j = l - i + 1; j <= r - i; ++j) {
        if (i + j > (k + 1) / 2 || i + j < l + r - k / 2)
          continue;
        const auto [x, y] = solve(i, j, (k + 1) / 2);
        a = min(a, x + 1);
        b = max(b, y + 1);
      }

    return dp[l][r][k] = {a, b};
  }
};
