class Solution {
 public:
  int lenLongestFibSubseq(vector<int>& A) {
    const int n = A.size();
    int ans = 0;
    vector<vector<int>> dp(n, vector<int>(n, 2));
    unordered_map<int, int> numToIndex;

    for (int i = 0; i < n; ++i)
      numToIndex[A[i]] = i;

    for (int j = 0; j < n; ++j)
      for (int k = j + 1; k < n; ++k) {
        const int ai = A[k] - A[j];
        if (ai < A[j] && numToIndex.count(ai)) {
          const int i = numToIndex[ai];
          dp[j][k] = dp[i][j] + 1;
          ans = max(ans, dp[j][k]);
        }
      }

    return ans;
  }
};
