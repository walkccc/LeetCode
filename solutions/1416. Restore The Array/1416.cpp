class Solution {
 public:
  int numberOfArrays(string s, int k) {
    constexpr int kMod = 1e9 + 7;
    const int n = s.length();

    vector<int> memo(n, -1);

    // dp(i) := # of arrays to restore s[i..n) w/ k
    function<int(int)> dp = [&](int i) {
      if (i == n)
        return 1;  // empty string """"
      if (s[i] == '0')
        return 0;  // leading zero
      if (memo[i] >= 0)
        return memo[i];

      int ans = 0;
      long num = 0;

      for (int j = i; j < n; ++j) {
        num = num * 10 + (s[j] - '0');
        if (num > k)
          break;
        ans = (ans + dp(j + 1)) % kMod;
      }

      return memo[i] = ans;
    };

    return dp(0);
  }
};
