class Solution {
 public:
  int minDeletionSize(vector<string>& strs) {
    const int n = strs.size();
    int ans = 0;
    // sorted[i] := true if strs[i] < strs[i + 1]
    vector<bool> sorted(n - 1);

    for (int j = 0; j < strs[0].length(); ++j) {
      int i;
      for (i = 0; i + 1 < n; ++i)
        if (!sorted[i] && strs[i][j] > strs[i + 1][j]) {
          ++ans;
          break;
        }
      // Already compared each pair, so update the sorted array if needed.
      if (i + 1 == n)
        for (i = 0; i + 1 < n; ++i)
          sorted[i] = sorted[i] || strs[i][j] < strs[i + 1][j];
    }

    return ans;
  }
};
