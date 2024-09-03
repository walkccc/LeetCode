class Solution {
 public:
  vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
    using P = pair<int, int>;
    vector<vector<vector<P>>> mem(n + 1,
                                  vector<vector<P>>(n + 1, vector<P>(n + 1)));
    const auto [a, b] = solve(firstPlayer, n - secondPlayer + 1, n, mem);
    return {a, b};
  }

 private:
  // Returns the (earliest, latest) pair, the first player is the l-th player
  // from the front, the second player is the r-th player from the end, and
  // there're k people.
  pair<int, int> solve(int l, int r, int k,
                       vector<vector<vector<pair<int, int>>>>& mem) {
    if (l == r)
      return {1, 1};
    if (l > r)
      swap(l, r);
    if (mem[l][r][k] != pair<int, int>{0, 0})
      return mem[l][r][k];

    int a = INT_MAX;
    int b = INT_MIN;

    // Enumerate all the possible positions.
    for (int i = 1; i <= l; ++i)
      for (int j = l - i + 1; j <= r - i; ++j) {
        if (i + j > (k + 1) / 2 || i + j < l + r - k / 2)
          continue;
        const auto [x, y] = solve(i, j, (k + 1) / 2, mem);
        a = min(a, x + 1);
        b = max(b, y + 1);
      }

    return mem[l][r][k] = {a, b};
  }
};
