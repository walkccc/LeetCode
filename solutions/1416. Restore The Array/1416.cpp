class Solution {
 public:
  int numberOfArrays(string s, int k) {
    // dp[i] := the number of arrays to restore s[i..n) with k
    dp.resize(s.length(), -1);
    return numberOfArrays(s, 0, k);
  }

 private:
  static constexpr int kMod = 1'000'000'007;
  vector<int> dp;

  int numberOfArrays(const string& s, int i, int k) {
    if (i == s.length())
      return 1;  // an empty string """"
    if (s[i] == '0')
      return 0;  // a leading zero
    if (dp[i] >= 0)
      return dp[i];

    int ans = 0;
    long num = 0;

    for (int j = i; j < s.length(); ++j) {
      num = num * 10 + (s[j] - '0');
      if (num > k)
        break;
      ans = (ans + numberOfArrays(s, j + 1, k)) % kMod;
    }

    return dp[i] = ans;
  }
};
