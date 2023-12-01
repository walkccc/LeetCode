class Solution {
 public:
  int countSteppingNumbers(string low, string high) {
    const string lowWithLeadingZeros =
        string(high.length() - low.length(), '0') + low;
    // dp[i][j][k1][k2] := the number of valid integers with size i and the
    // previous digit j. The variables k1 and k2 indicate tight constraints
    // (0/1) for `low` and `high` respectively.
    dp.resize(high.length(),
              vector<vector<vector<int>>>(
                  11, vector<vector<int>>(2, vector<int>(2, -1))));
    return count(lowWithLeadingZeros, high, 0, 10, /*isLeadingZero=*/true, true,
                 true);
  }

 private:
  static constexpr int kMod = 1'000'000'007;
  vector<vector<vector<vector<int>>>> dp;

  int count(const string& low, const string& high, int i, int prevDigit,
            bool isLeadingZero, bool isTight1, bool isTight2) {
    if (i == high.length())
      return 1;
    if (dp[i][prevDigit][isTight1][isTight2] != -1)
      return dp[i][prevDigit][isTight1][isTight2];

    int res = 0;
    const int minDigit = isTight1 ? low[i] - '0' : 0;
    const int maxDigit = isTight2 ? high[i] - '0' : 9;

    for (int d = minDigit; d <= maxDigit; ++d) {
      const bool nextIsTight1 = isTight1 && (d == minDigit);
      const bool nextIsTight2 = isTight2 && (d == maxDigit);
      if (isLeadingZero)
        // Can place any digit in [minDigit, maxDigit].
        res += count(low, high, i + 1, d, isLeadingZero && d == 0, nextIsTight1,
                     nextIsTight2);
      else if (abs(d - prevDigit) == 1)
        // Can only place prevDigit - 1 or prevDigit + 1.
        res += count(low, high, i + 1, d, false, nextIsTight1, nextIsTight2);
      res %= kMod;
    }

    return dp[i][prevDigit][isTight1][isTight2] = res;
  }
};
