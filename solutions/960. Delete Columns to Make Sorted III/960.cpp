class Solution {
 public:
  int minDeletionSize(vector<string>& strs) {
    const int k = strs[0].length();
    // dp[i] the length of LIS ending in strs[*][i]
    vector<int> dp(k, 1);

    for (int i = 1; i < k; ++i)
      for (int j = 0; j < i; ++j)
        if (ranges::all_of(strs, [&](const string& s) { return s[j] <= s[i]; }))
          dp[i] = max(dp[i], dp[j] + 1);

    return k - ranges::max(dp);
  }
};
