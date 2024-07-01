class Solution {
 public:
  // Same as 1012. Numbers With Repeated Digits
  int countSpecialNumbers(int n) {
    const int digitSize = log10(n) + 1;
    vector<vector<vector<int>>> mem(
        digitSize + 1, vector<vector<int>>(1 << 10, vector<int>(2, -1)));
    return count(to_string(n), 0, 0, true, mem) - 1;  // - 0;
  }

 private:
  // Returns the number of special integers, considering the i-th digit, where
  // `used` is the bitmask of the used digits, and `isTight` indicates if the
  // current digit is tightly bound.
  int count(const string& s, int i, int used, bool isTight,
            vector<vector<vector<int>>>& mem) {
    if (i == s.length())
      return 1;
    if (mem[i][used][isTight] != -1)
      return mem[i][used][isTight];

    int res = 0;

    const int maxDigit = isTight ? s[i] - '0' : 9;
    for (int d = 0; d <= maxDigit; ++d) {
      // `d` is used.
      if (used >> d & 1)
        continue;
      // Use `d` now.
      const bool nextIsTight = isTight && (d == maxDigit);
      if (used == 0 && d == 0)  // Don't count leading 0s as used.
        res += count(s, i + 1, used, nextIsTight, mem);
      else
        res += count(s, i + 1, used | 1 << d, nextIsTight, mem);
    }

    return mem[i][used][isTight] = res;
  }
};
