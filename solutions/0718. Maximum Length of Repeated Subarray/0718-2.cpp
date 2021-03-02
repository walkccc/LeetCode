class Solution {
 public:
  int findLength(vector<int>& A, vector<int>& B) {
    const int m = A.size();
    const int n = B.size();

    int ans = 0;
    vector<int> dp(n + 1);

    for (int i = m - 1; i >= 0; --i)
      for (int j = 0; j < n; ++j) {  // the order is important
        dp[j] = A[i] == B[j] ? dp[j + 1] + 1 : 0;
        ans = max(ans, dp[j]);
      }

    return ans;
  }
};
