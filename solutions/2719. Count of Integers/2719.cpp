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
  // `sum` is the maximum digit sum, `isTight1` indicates if the current digit
  // is tightly bound for `num1` and `isTight2` indicates if the current digit
  // is tightly bound for `num2`
  int count(const string& num1, const string& num2, int i, int sum,
            bool isTight1, bool isTight2,
            vector<vector<vector<vector<int>>>>& mem) {
    if (sum < 0)
      return 0;
    if (i == num2.length())
      return 1;
    if (mem[i][sum][isTight1][isTight2] != -1)
      return mem[i][sum][isTight1][isTight2];

    int res = 0;

    const int minDigit = isTight1 ? num1[i] - '0' : 0;
    const int maxDigit = isTight2 ? num2[i] - '0' : 9;
    for (int d = minDigit; d <= maxDigit; ++d) {
      const bool nextIsTight1 = isTight1 && (d == minDigit);
      const bool nextIsTight2 = isTight2 && (d == maxDigit);
      res += count(num1, num2, i + 1, sum - d, nextIsTight1, nextIsTight2, mem);
      res %= kMod;
    }

    return mem[i][sum][isTight1][isTight2] = res;
  }
};
