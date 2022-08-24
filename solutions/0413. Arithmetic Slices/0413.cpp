class Solution {
 public:
  int numberOfArithmeticSlices(vector<int>& A) {
    const int n = A.size();
    if (n < 3)
      return 0;

    vector<int> dp(n);  // # arithmetic slices ends at i

    for (int i = 2; i < A.size(); ++i)
      if (A[i] - A[i - 1] == A[i - 1] - A[i - 2])
        dp[i] = dp[i - 1] + 1;

    return accumulate(begin(dp), end(dp), 0);
  }
};
