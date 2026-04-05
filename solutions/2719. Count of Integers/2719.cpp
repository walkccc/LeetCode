class Solution {
 public:
  int count(string num1, string num2, int min_sum, int max_sum) {
    const string num1WithLeadingZeros =
        string(num2.length() - num1.length(), '0') + num1;
    vector<vector<vector<vector<int>>>> mem(
        num2.length(),
        vector<vector<vector<int>>>(
            max_sum + 1, vector<vector<int>>(2, vector<int>(2, -1))));
    return (count(num1WithLeadingZeros, num2, 0, max_sum, true, true, mem) -
            count(num1WithLeadingZeros, num2, 0, min_sum - 1, true, true, mem) +
            kMod) %
           kMod;
  }

 private:
  static constexpr int kMod = 1'000'000'007;

  // Returns the number of valid integers, considering the i-th digit, where
  // `sum` is the maximum digit sum, `tight1` indicates if the current digit
  // is tightly bound for `num1` and `tight2` indicates if the current digit
  // is tightly bound for `num2`
  int count(const string& num1, const string& num2, int i, int sum, bool tight1,
            bool tight2, vector<vector<vector<vector<int>>>>& mem) {
    if (sum < 0)
      return 0;
    if (i == num2.length())
      return 1;
    if (mem[i][sum][tight1][tight2] != -1)
      return mem[i][sum][tight1][tight2];

    int res = 0;

    const int minDigit = tight1 ? num1[i] - '0' : 0;
    const int maxDigit = tight2 ? num2[i] - '0' : 9;
    for (int d = minDigit; d <= maxDigit; ++d) {
      const bool nextTight1 = tight1 && (d == minDigit);
      const bool nextTight2 = tight2 && (d == maxDigit);
      res += count(num1, num2, i + 1, sum - d, nextTight1, nextTight2, mem);
      res %= kMod;
    }

    return mem[i][sum][tight1][tight2] = res;
  }
};
