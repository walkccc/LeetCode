class Solution {
 public:
  int numSimilarGroups(vector<string>& A) {
    int ans = 0;
    vector<bool> seen(A.size());

    // dfs on string A[i]
    function<void(int)> dfs = [&](int i) {
      seen[i] = true;
      for (int j = 0; j < A.size(); ++j)
        if (!seen[j] && isSimilar(A[i], A[j]))
          dfs(j);
    };

    for (int i = 0; i < A.size(); ++i)
      if (!seen[i]) {
        dfs(i);
        ++ans;
      }

    return ans;
  }

 private:
  bool isSimilar(const string& X, const string& Y) {
    int diff = 0;
    for (int i = 0; i < X.length(); ++i)
      if (X[i] != Y[i] && ++diff > 2)
        return false;
    return true;
  }
};