class Solution {
 public:
  int beautifulPartitions(string s, int k, int minLength) {
    if (!isPrime(s.front()) || isPrime(s.back()))
      return 0;

    this->minLength = minLength;
    // dp[i][k] := the number of beautiful partitions of s[i..n) with k bars (|)
    // left
    dp.resize(s.length(), vector<int>(k, -1));
    return partitions(s, minLength, k - 1);
  }

 private:
  static constexpr int kMod = 1'000'000'007;
  int minLength;
  vector<vector<int>> dp;

  int partitions(const string& s, int i, int k) {
    if (i <= s.length() && k == 0)
      return 1;
    if (i >= s.length())
      return 0;
    if (dp[i][k] != -1)
      return dp[i][k];

    // Don't split between s[i - 1] and s[i].
    int ans = partitions(s, i + 1, k) % kMod;

    // Split between s[i - 1] and s[i].
    if (isPrime(s[i]) && !isPrime(s[i - 1]))
      ans += partitions(s, i + minLength, k - 1);

    return dp[i][k] = ans % kMod;
  }

  bool isPrime(char c) {
    return c == '2' || c == '3' || c == '5' || c == '7';
  }
};
