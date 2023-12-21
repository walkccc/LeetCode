class Solution {
 public:
  int numSimilarGroups(vector<string>& strs) {
    int ans = 0;
    vector<bool> seen(strs.size());

    for (int i = 0; i < strs.size(); ++i)
      if (!seen[i]) {
        dfs(strs, i, seen);
        ++ans;
      }

    return ans;
  }

 private:
  void dfs(const vector<string>& strs, int i, vector<bool>& seen) {
    seen[i] = true;
    for (int j = 0; j < strs.size(); ++j)
      if (!seen[j] && isSimilar(strs[i], strs[j]))
        dfs(strs, j, seen);
  }

  bool isSimilar(const string& X, const string& Y) {
    int diff = 0;
    for (int i = 0; i < X.length(); ++i)
      if (X[i] != Y[i] && ++diff > 2)
        return false;
    return true;
  }
};
