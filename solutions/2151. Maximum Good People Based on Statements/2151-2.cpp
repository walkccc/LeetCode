class Solution {
 public:
  int maximumGood(vector<vector<int>>& statements) {
    const int maxMask = 1 << statements.size();
    int ans = 0;

    for (int mask = 0; mask < maxMask; ++mask)
      if (isValid(statements, mask))
        ans = max(ans, __builtin_popcount(mask));

    return ans;
  }

 private:
  bool isValid(const vector<vector<int>>& statements, int mask) {
    for (int i = 0; i < statements.size(); ++i) {
      if (!(mask >> i & 1))  // i-th person is bad, no need to check
        continue;
      for (int j = 0; j < statements.size(); ++j) {
        if (statements[i][j] == 2)
          continue;
        if (statements[i][j] != (mask >> j & 1))
          return false;
      }
    }
    return true;
  }
};
