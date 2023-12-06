class Solution {
 public:
  int numberOfBeautifulIntegers(int low, int high, int k) {
    // dp[i][even][odd][remainder][k1][k2] := the number of valid integers of
    // size i with counts of even `even` digits and odd `odd` digits, and the
    // current number modulo k equals remainder. The variables k1 and k2
    // indicate tight constraints (0/1) for `low` and `high` respectively.
    const string lowString = to_string(low);
    const string highString = to_string(high);
    const string lowWithLeadingZeros =
        string(highString.length() - lowString.length(), '0') + lowString;
    dp.resize(
        highString.length(),
        vector<vector<vector<vector<vector<int>>>>>(
            10, vector<vector<vector<vector<int>>>>(
                    10, vector<vector<vector<int>>>(
                            k, vector<vector<int>>(2, vector<int>(2, -1))))));
    return count(lowWithLeadingZeros, highString, k, 0, 0, 0, 0, true, true,
                 true);
  }

 private:
  vector<vector<vector<vector<vector<vector<int>>>>>> dp;

  int count(const string& low, const string& high, int k, int i, int even,
            int odd, int remainder, bool isLeadingZero, bool isTight1,
            bool isTight2) {
    if (i == high.length())
      return !isLeadingZero && even == odd && remainder == 0;
    if (dp[i][even][odd][remainder][isTight1][isTight2] != -1)
      return dp[i][even][odd][remainder][isTight1][isTight2];

    int res = 0;
    const int minDigit = isTight1 ? low[i] - '0' : 0;
    const int maxDigit = isTight2 ? high[i] - '0' : 9;

    for (int d = minDigit; d <= maxDigit; ++d) {
      const int nextEven = even + ((!isLeadingZero || d > 0) && d % 2 == 0);
      const int nextOdd = odd + (d % 2 == 1);
      const int nextRemainder = (remainder * 10 + d) % k;
      const bool nextIsTight1 = isTight1 && (d == minDigit);
      const bool nextIsTight2 = isTight2 && (d == maxDigit);
      res += count(low, high, k, i + 1, nextEven, nextOdd, nextRemainder,
                   isLeadingZero && d == 0, nextIsTight1, nextIsTight2);
    }

    return dp[i][even][odd][remainder][isTight1][isTight2] = res;
  }
};
