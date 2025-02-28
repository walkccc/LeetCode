class Solution {
 public:
  bool maxSubstringLength(string s, int k) {
    const int n = s.length();
    vector<int> first(26, n);
    vector<int> last(26, -1);
    vector<char> seenOrder;
    // dp[i] := the maximum disjoint special substrings for the first i letters
    vector<int> dp(n + 1);

    for (int i = 0; i < n; ++i) {
      const char c = s[i];
      const int a = c - 'a';
      if (first[a] == n) {
        first[a] = i;
        seenOrder.push_back(c);
      }
      last[a] = i;
    }

    for (const char c : seenOrder) {
      const int a = c - 'a';
      for (int j = first[a]; j < last[a]; ++j) {
        const int b = s[j] - 'a';
        first[a] = min(first[a], first[b]);
        last[a] = max(last[a], last[b]);
      }
    }

    for (int i = 0; i < n; ++i) {
      const char c = s[i];
      const int a = c - 'a';
      if (last[a] != i || (first[a] == 0 && i == n - 1))
        dp[i + 1] = dp[i];
      else  // Start a new special substring.
        dp[i + 1] = max(dp[i], 1 + dp[first[a]]);
    }

    return dp[n] >= k;
  }
};
