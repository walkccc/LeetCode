class Solution {
 public:
  int countTexts(string pressedKeys) {
    constexpr int kMod = 1'000'000'007;
    const int n = pressedKeys.length();
    // dp[i] := # of possible text messages of s[i:]
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
  // return true if s[i:i + k] are same chars
  bool isSame(const string& s, int i, int k) {
    if (i + k > s.length())
      return false;
    for (int j = i + 1; j < i + k; ++j)
      if (s[j] != s[i])
        return false;
    return true;
  }
};
