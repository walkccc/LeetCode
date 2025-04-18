class Solution {
 public:
  int numberOfArrays(string s, int k) {
    vector<int> mem(s.length(), -1);
    return numberOfArrays(s, 0, k, mem);
  }

 private:
  static constexpr int kMod = 1'000'000'007;

  // Returns the number of arrays to restore s[i..n) with k.
  int numberOfArrays(const string& s, int i, int k, vector<int>& mem) {
    if (i == s.length())
      return 1;  // an empty string ""
    if (s[i] == '0')
      return 0;  // a leading zero
    if (mem[i] != -1)
      return mem[i];

    int res = 0;
    long num = 0;

    for (int j = i; j < s.length(); ++j) {
      num = num * 10 + (s[j] - '0');
      if (num > k)
        break;
      res = (res + numberOfArrays(s, j + 1, k, mem)) % kMod;
    }

    return mem[i] = res;
  }
};
