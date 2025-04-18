class Solution {
 public:
  int numberOfBeautifulIntegers(int low, int high, int k) {
    const string lowString = to_string(low);
    const string highString = to_string(high);
    const string lowWithLeadingZeros =
        string(highString.length() - lowString.length(), '0') + lowString;
    vector<vector<vector<vector<vector<vector<int>>>>>> mem(
        highString.length(),
        vector<vector<vector<vector<vector<int>>>>>(
            10, vector<vector<vector<vector<int>>>>(
                    10, vector<vector<vector<int>>>(
                            k, vector<vector<int>>(2, vector<int>(2, -1))))));
    return count(lowWithLeadingZeros, highString, k, 0, 0, 0, 0, true, true,
                 true, mem);
  }

 private:
  // Returns the number of beautiful integers, considering the i-th digit with
  // counts of even `even` digits and odd `odd` digits, where the current number
  // modulo k equals remainder, `tight1` indicates if the current digit is
  // tightly bound for `low` and `tight2` indicates if the current digit is
  // tightly bound for `high`
  int count(const string& low, const string& high, int k, int i, int even,
            int odd, int remainder, bool isLeadingZero, bool tight1,
            bool tight2,
            vector<vector<vector<vector<vector<vector<int>>>>>>& mem) {
    if (i == high.length())
      return !isLeadingZero && even == odd && remainder == 0;
    if (mem[i][even][odd][remainder][tight1][tight2] != -1)
      return mem[i][even][odd][remainder][tight1][tight2];

    int res = 0;
    const int minDigit = tight1 ? low[i] - '0' : 0;
    const int maxDigit = tight2 ? high[i] - '0' : 9;

    for (int d = minDigit; d <= maxDigit; ++d) {
      const int nextEven = even + ((!isLeadingZero || d > 0) && d % 2 == 0);
      const int nextOdd = odd + (d % 2 == 1);
      const int nextRemainder = (remainder * 10 + d) % k;
      const bool nextTight1 = tight1 && (d == minDigit);
      const bool nextTight2 = tight2 && (d == maxDigit);
      res += count(low, high, k, i + 1, nextEven, nextOdd, nextRemainder,
                   isLeadingZero && d == 0, nextTight1, nextTight2, mem);
    }

    return mem[i][even][odd][remainder][tight1][tight2] = res;
  }
};
