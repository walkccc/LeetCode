class Solution {
 public:
  int beautifulPartitions(string s, int k, int minLength) {
    if (!isPrime(s.front()) || isPrime(s.back()))
      return 0;
    vector<vector<int>> mem(s.length(), vector<int>(k, -1));
    return beautifulPartitions(s, minLength, k - 1, minLength, mem);
  }

 private:
  static constexpr int kMod = 1'000'000'007;

  // Returns the number of beautiful partitions of s[i..n) with k bars (|) left.
  int beautifulPartitions(const string& s, int i, int k, int minLength,
                          vector<vector<int>>& mem) {
    if (i <= s.length() && k == 0)
      return 1;
    if (i >= s.length())
      return 0;
    if (mem[i][k] != -1)
      return mem[i][k];

    // Don't split between s[i - 1] and s[i].
    int res = beautifulPartitions(s, i + 1, k, minLength, mem) % kMod;

    // Split between s[i - 1] and s[i].
    if (isPrime(s[i]) && !isPrime(s[i - 1]))
      res += beautifulPartitions(s, i + minLength, k - 1, minLength, mem);

    return mem[i][k] = res % kMod;
  }

  bool isPrime(char c) {
    return c == '2' || c == '3' || c == '5' || c == '7';
  }
};
