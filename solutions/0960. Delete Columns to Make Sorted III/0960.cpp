class Solution {
 public:
  int minDeletionSize(vector<string>& A) {
    const int n = A[0].length();
    // dp[i] := LIS ending at A[*][i]
    vector<int> dp(n, 1);

    for (int i = 1; i < n; ++i)
      for (int j = 0; j < i; ++j)
        if (all_of(begin(A), end(A),
                   [&](const string& a) { return a[j] <= a[i]; }))
          dp[i] = max(dp[i], dp[j] + 1);

    return n - *max_element(begin(dp), end(dp));
  }
};
