class Solution {
 public:
  int countTexts(string pressedKeys) {
    constexpr int kMod = 1'000'000'007;
    const int n = pressedKeys.length();
    // dp[i] := the number of possible text messages of pressedKeys[i..n)
    vector<long> dp(n + 1);
    dp[n] = 1;  // ""

    for (int i = n - 1; i >= 0; --i) {
      dp[i] = dp[i + 1];
      if (isSame(pressedKeys, i, 2))
        dp[i] += dp[i + 2];
      if (isSame(pressedKeys, i, 3))
        dp[i] += dp[i + 3];
      if ((pressedKeys[i] == '7' || pressedKeys[i] == '9') &&
          isSame(pressedKeys, i, 4))
        dp[i] += dp[i + 4];
      dp[i] %= kMod;
    }

    return dp[0];
  }

 private:
  // Returns true if s[i..i + k) are the same digits.
  bool isSame(const string& s, int i, int k) {
    if (i + k > s.length())
      return false;
    for (int j = i + 1; j < i + k; ++j)
      if (s[j] != s[i])
        return false;
    return true;
  }
};
