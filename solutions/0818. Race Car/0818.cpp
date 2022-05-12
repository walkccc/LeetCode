class Solution {
 public:
  int racecar(int target) {
    dp.resize(target + 1, -1);
    return rc(target);
  }

 private:
  vector<int> dp;

  int rc(int i) {
    if (dp[i] >= 0)
      return dp[i];

    int ans = INT_MAX;
    int x = 1;             // xA: (2^x - 1) unit distance
    int j = (1 << x) - 1;  // j = 2^x - 1, k = 2^y - 1

    // (xA + 1R) + (yA + 1R) + rc(i - (j - k))
    for (; j < i; j = (1 << ++x) - 1)
      for (int y = 0, k = 0; k < j; k = (1 << ++y) - 1)
        ans = min(ans, (x + 1) + (y + 1) + rc(i - (j - k)));

    // xA || (xA + 1R) + rc(j - i)
    ans = min(ans, i == j ? x : x + 1 + rc(j - i));
    return dp[i] = ans;
  }
};
