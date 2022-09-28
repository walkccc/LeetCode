class Solution {
 public:
  int findDerangement(int n) {
    dp.resize(n + 1);
    return find(n);
  }

 private:
  constexpr static int kMod = 1'000'000'007;
  vector<int> dp;

  int find(int i) {
    if (i == 0)
      return 1;
    if (i == 1)
      return 0;
    if (dp[i])
      return dp[i];
    return dp[i] = (i - 1L) * (find(i - 1) + find(i - 2)) % kMod;
  }
};
