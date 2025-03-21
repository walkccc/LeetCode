class Solution {
 public:
  int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
    const unordered_set<int> target{targetIndices.begin(), targetIndices.end()};
    vector<vector<int>> mem(source.length(), vector<int>(pattern.length(), -1));
    const int ans = maxRemovals(source, pattern, 0, 0, target, mem);
    return ans == INT_MIN ? 0 : ans;
  }

 private:
  // Returns the maximum number of operations that can be performed for
  // source[i..m) and pattern[j..n).
  int maxRemovals(const string& source, const string& pattern, int i, int j,
                  const unordered_set<int>& target, vector<vector<int>>& mem) {
    if (i == source.length())
      return j == pattern.length() ? 0 : INT_MIN;
    if (j == pattern.length())
      return (target.contains(i) ? 1 : 0) +
             maxRemovals(source, pattern, i + 1, j, target, mem);
    if (mem[i][j] != -1)
      return mem[i][j];
    const int pick =
        source[i] == pattern[j]
            ? maxRemovals(source, pattern, i + 1, j + 1, target, mem)
            : INT_MIN;
    const int skip = (target.contains(i) ? 1 : 0) +
                     maxRemovals(source, pattern, i + 1, j, target, mem);
    return mem[i][j] = max(pick, skip);
  };
};
