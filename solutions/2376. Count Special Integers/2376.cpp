class Solution {
 public:
  // Same as 1012. Numbers With Repeated Digits
  int countSpecialNumbers(int n) {
    const int digitSize = log10(n) + 1;
    // dp[i][j][k] := the number of special integers with current digit i and
    // `usedMask` j, where k is 0/1 tight constraint
    dp.resize(digitSize + 1, vector<vector<int>>(1 << 10, vector<int>(2, -1)));
    return count(to_string(n), 0, 0, true) - 1;  // - 0;
  }

 private:
  vector<vector<vector<int>>> dp;

  int count(const string& s, int i, int usedMask, bool isTight) {
    if (i == s.length())
      return 1;
    if (dp[i][usedMask][isTight] != -1)
      return dp[i][usedMask][isTight];

    int res = 0;

    const int maxDigit = isTight ? s[i] - '0' : 9;
    for (int d = 0; d <= maxDigit; ++d) {
      // `d` is used.
      if (usedMask >> d & 1)
        continue;
      // Use `d` now.
      const bool nextIsTight = isTight && (d == maxDigit);
      if (usedMask == 0 && d == 0)  // Don't count leading 0s as used.
        res += count(s, i + 1, usedMask, nextIsTight);
      else
        res += count(s, i + 1, usedMask | 1 << d, nextIsTight);
    }

    return dp[i][usedMask][isTight] = res;
  }
};
