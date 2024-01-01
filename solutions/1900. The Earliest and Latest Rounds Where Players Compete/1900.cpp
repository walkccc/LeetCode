class Solution {
 public:
  vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
    // dp[i][j][k] := the (earliest, latest) pair, the first player is the i-th
    // player from the front, the second player is the j-th player from the end,
    // and there're k people
    dp.resize(n + 1, vector<vector<P>>(n + 1, vector<P>(n + 1)));
    const auto [a, b] = solve(firstPlayer, n - secondPlayer + 1, n);
    return {a, b};
  }

 private:
  typedef pair<int, int> P;
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

    // Enumerate all the possible positions.
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
