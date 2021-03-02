class Solution {
 public:
  int numberOfArithmeticSlices(vector<int>& A) {
    int ans = 0;
    int dp = 0;  // # arithmetic slices ends at i

    for (int i = 2; i < A.size(); ++i)
      if (A[i] - A[i - 1] == A[i - 1] - A[i - 2])
        ans += ++dp;
      else
        dp = 0;

    return ans;
  }
};
