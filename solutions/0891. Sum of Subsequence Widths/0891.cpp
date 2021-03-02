class Solution {
 public:
  int sumSubseqWidths(vector<int>& A) {
    const int n = A.size();
    const int kMod = 1e9 + 7;

    int ans = 0;
    long exp = 1;

    sort(begin(A), end(A));

    for (int i = 0; i < n; ++i, exp = exp * 2 % kMod)
      ans = (ans + A[i] * exp - A[n - i - 1] * exp) % kMod;

    return ans;
  }
};
