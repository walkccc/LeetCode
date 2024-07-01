class Solution {
 public:
  int maxEnvelopes(vector<vector<int>>& envelopes) {
    ranges::sort(envelopes, [](const auto& a, const auto& b) {
      return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
    });

    // Same as 300. Longest Increasing Subsequence
    int ans = 0;
    vector<int> dp(envelopes.size());

    for (const vector<int>& e : envelopes) {
      int l = 0;
      int r = ans;
      while (l < r) {
        const int m = (l + r) / 2;
        if (dp[m] >= e[1])
          r = m;
        else
          l = m + 1;
      }
      dp[l] = e[1];
      if (l == ans)
        ++ans;
    }

    return ans;
  }
};
