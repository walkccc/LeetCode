class Solution {
 public:
  int numDecodings(string s) {
    constexpr int kMod = 1'000'000'007;
    const int n = s.length();
    long prev2 = 1;
    long prev1 = count(s[n - 1]);

    for (int i = n - 2; i >= 0; --i) {
      long dp = count(s[i], s[i + 1]) * prev2 + count(s[i]) * prev1;
      dp %= kMod;
      prev2 = prev1;
      prev1 = dp;
    }

    return prev1;
  }

 private:
  int count(char c) {
    if (c == '*')
      return 9;
    return c != '0';
  }

  int count(char c1, char c2) {
    if (c1 == '*' && c2 == '*')  // c1c2: [11-19, 21-26]
      return 15;
    if (c1 == '*') {
      if ('0' <= c2 && c2 <= '6')  // c1: [1-2]
        return 2;
      else  // c1: [1]
        return 1;
    }
    if (c2 == '*') {
      if (c1 == '1')  // c2: [1-9]
        return 9;
      if (c1 == '2')  // c2: [1-6]
        return 6;
      return 0;
    }
    return c1 == '1' || (c1 == '2' && c2 <= '6');
  }
};
