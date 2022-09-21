class Solution {
 public:
  int numDupDigitsAtMostN(int n) {
    return n - countSpecialNumbers(n);
  }

 private:
  // same as 2376. Count Special Integers
  int countSpecialNumbers(int n) {
    const int digitSize = log10(n) + 1;
    // dp[i][j][k] := # of special integers that belong to the interval
    // [0, 10^i] with `usedMask` j, where k is 0/1 tight constraint
    dp.resize(digitSize + 1, vector<vector<int>>(1 << 10, vector<int>(2, -1)));
    return count(to_string(n), digitSize, 0, true) - 1;  // - 0;
  }

  vector<vector<vector<int>>> dp;

  int count(const string& s, int digitSize, int usedMask, bool isTight) {
    if (digitSize == 0)
      return 1;
    if (dp[digitSize][usedMask][isTight] != -1)
      return dp[digitSize][usedMask][isTight];

    int ans = 0;
    const int maxDigit = isTight ? s[s.length() - digitSize] - '0' : 9;

    for (int digit = 0; digit <= maxDigit; ++digit) {
      // `digit` is used
      if (usedMask >> digit & 1)
        continue;
      // use `digit` now
      const bool nextIsTight = isTight && (digit == maxDigit);
      if (usedMask == 0 && digit == 0)  // don't count leading 0s as used
        ans += count(s, digitSize - 1, usedMask, nextIsTight);
      else
        ans += count(s, digitSize - 1, usedMask | 1 << digit, nextIsTight);
    }

    return dp[digitSize][usedMask][isTight] = ans;
  }
};
