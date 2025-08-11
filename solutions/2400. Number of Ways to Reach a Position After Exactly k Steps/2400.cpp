class Solution {
 public:
  int numberOfWays(int startPos, int endPos, int k) {
    // leftStep + rightStep = k
    // rightStep - leftStep = endPos - startPos
    //        2 * rightStep = k + endPos - startPos
    //            rightStep = (k + endPos - startPos) / 2
    const int val = k + endPos - startPos;
    if (val < 0 || val % 2 == 1)
      return 0;
    const int rightStep = val / 2;
    const int leftStep = k - rightStep;
    if (leftStep < 0)
      return 0;
    return nCk(leftStep + rightStep, min(leftStep, rightStep));
  }

 private:
  static constexpr int kMod = 1'000'000'007;

  // C(n, k) = C(n - 1, k) + C(n - 1, k - 1)
  int nCk(int n, int k) {
    // dp[i] := C(n so far, i)
    vector<int> dp(k + 1);
    dp[0] = 1;

    while (n-- > 0)  // Calculate n times.
      for (int j = k; j > 0; --j) {
        dp[j] += dp[j - 1];
        dp[j] %= kMod;
      }

    return dp[k];
  }
};
