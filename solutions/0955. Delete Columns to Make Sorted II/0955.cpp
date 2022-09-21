class Solution {
 public:
  int minDeletionSize(vector<string>& A) {
    const int n = A[0].length();
    int ans = 0;
    // sorted[i] := true if A[i] < A[i + 1]
    vector<bool> sorted(A.size() - 1);

    for (int j = 0; j < n; ++j) {
      int i;
      for (i = 0; i + 1 < A.size(); ++i)
        if (!sorted[i] && A[i][j] > A[i + 1][j]) {
          ++ans;
          break;
        }
      // already compared each pair, update the sorted array if needed
      if (i + 1 == A.size())
        for (i = 0; i + 1 < A.size(); ++i)
          sorted[i] = sorted[i] || A[i][j] < A[i + 1][j];
    }

    return ans;
  }
};
