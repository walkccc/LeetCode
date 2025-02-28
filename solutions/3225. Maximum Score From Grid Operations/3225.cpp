class Solution {
 public:
  long long maximumScore(vector<vector<int>>& grid) {
    const int n = grid.size();
    // prefix[j][i] := the sum of the first i elements in the j-th column
    vector<vector<long>> prefix(n, vector<long>(n + 1));
    // prevPick[i] := the maximum achievable score up to the previous column,
    // where the bottommost selected element in that column is in row (i - 1)
    vector<long> prevPick(n + 1);
    // prevSkip[i] := the maximum achievable score up to the previous column,
    // where the bottommost selected element in the column before the previous
    // one is in row (i - 1)
    vector<long> prevSkip(n + 1);

    for (int j = 0; j < n; ++j)
      for (int i = 0; i < n; ++i)
        prefix[j][i + 1] = prefix[j][i] + grid[i][j];

    for (int j = 1; j < n; ++j) {
      vector<long> currPick(n + 1);
      vector<long> currSkip(n + 1);
      // Consider all possible combinations of the number of current and
      // previous selected elements.
      for (int curr = 0; curr <= n; ++curr)
        for (int prev = 0; prev <= n; ++prev)
          if (curr > prev) {
            // 1. The current bottom is deeper than the previous bottom.
            // Get the score of grid[prev..curr)[j - 1] for pick and skip.
            const long score = prefix[j - 1][curr] - prefix[j - 1][prev];
            currPick[curr] = max(currPick[curr], prevSkip[prev] + score);
            currSkip[curr] = max(currSkip[curr], prevSkip[prev] + score);
          } else {
            // 2. The previous bottom is deeper than the current bottom.
            // Get the score of grid[curr..prev)[j] for pick only.
            const long score = prefix[j][prev] - prefix[j][curr];
            currPick[curr] = max(currPick[curr], prevPick[prev] + score);
            currSkip[curr] = max(currSkip[curr], prevPick[prev]);
          }
      prevPick = std::move(currPick);
      prevSkip = std::move(currSkip);
    }

    return ranges::max(prevPick);
  }
};
