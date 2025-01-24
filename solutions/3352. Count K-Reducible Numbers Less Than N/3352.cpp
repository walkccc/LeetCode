class Solution {
 public:
  int countKReducibleNumbers(string s, int k) {
    vector<vector<vector<int>>> mem(
        s.length(), vector<vector<int>>(s.length() + 1, vector<int>(2, -1)));
    return count(s, 0, 0, true, k, getOps(s), mem) - 1;  // - 0
  }

 private:
  static constexpr int kMod = 1'000'000'007;

  // Returns the number of positive integers less than n that are k-reducible,
  // considering the i-th digit, where `setBits` is the number of set bits in
  // the current number, and `isTight` indicates if the current digit is
  // tightly bound.
  int count(const string& s, int i, int setBits, bool isTight, int k,
            const vector<int>& ops, vector<vector<vector<int>>>& mem) {
    if (i == s.length())
      return (ops[setBits] < k && !isTight) ? 1 : 0;
    if (mem[i][setBits][isTight] != -1)
      return mem[i][setBits][isTight];

    int res = 0;
    const int maxDigit = isTight ? s[i] - '0' : 1;

    for (int d = 0; d <= maxDigit; ++d) {
      const bool nextIsTight = isTight && (d == maxDigit);
      res += count(s, i + 1, setBits + d, nextIsTight, k, ops, mem);
      res %= kMod;
    }

    return mem[i][setBits][isTight] = res;
  };

  // Returns the number of operations to reduce a number to 0.
  vector<int> getOps(string& s) {
    vector<int> ops(s.length() + 1);
    for (int num = 2; num <= s.length(); ++num)
      ops[num] = 1 + ops[__builtin_popcount(num)];
    return ops;
  }
};
