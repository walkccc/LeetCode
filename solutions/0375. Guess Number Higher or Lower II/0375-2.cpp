class Solution {
 public:
  int getMoneyAmount(int n) {
    vector<vector<int>> memo(n + 1, vector<int>(n + 1, 0));

    function<int(int, int)> dp = [&](int l, int r) {
      if (l >= r) return 0;
      int& ans = memo[l][r];
      if (ans) return ans;

      ans = INT_MAX;
      for (int i = l; i <= r; ++i)
        ans = min(ans, max(dp(l, i - 1), dp(i + 1, r)) + i);

      return ans;
    };

    return dp(1, n);
  }
};