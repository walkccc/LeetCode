class Solution {
 public:
  int numberOfArithmeticSlices(vector<int>& A) {
    const int n = A.size();

    int ans = 0;
    // dp[i][j] := # of subseqs end w/ A[j] A[i]
    vector<vector<int>> dp(n, vector<int>(n));
    unordered_map<long, vector<int>> numToIndices;

    for (int i = 0; i < n; ++i)
      numToIndices[A[i]].push_back(i);

    for (int i = 0; i < n; ++i)
      for (int j = 0; j < i; ++j) {
        const long target = (long)A[j] * 2 - A[i];
        if (numToIndices.count(target))
          for (const int k : numToIndices[target])
            if (k < j)
              dp[i][j] += (dp[j][k] + 1);
        ans += dp[i][j];
      }

    return ans;
  }
};
