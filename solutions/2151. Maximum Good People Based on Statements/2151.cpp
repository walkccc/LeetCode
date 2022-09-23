class Solution {
 public:
  int maximumGood(vector<vector<int>>& statements) {
    int ans = 0;
    dfs(statements, {}, 0, 0, ans);
    return ans;
  }

 private:
  void dfs(const vector<vector<int>>& statements, vector<int>&& good, int i,
           int count, int& ans) {
    if (i == statements.size()) {
      if (isValid(statements, good))
        ans = max(ans, count);
      return;
    }

    good.push_back(0);  // assume i-th person is bad
    dfs(statements, move(good), i + 1, count, ans);
    good.back() = 1;  // assume i-th person is good
    dfs(statements, move(good), i + 1, count + 1, ans);
    good.pop_back();
  }

  bool isValid(const vector<vector<int>>& statements, const vector<int>& good) {
    for (int i = 0; i < good.size(); ++i) {
      if (!good[i])  // i-th person is bad, no need to check
        continue;
      for (int j = 0; j < statements.size(); ++j) {
        if (statements[i][j] == 2)
          continue;
        if (statements[i][j] != good[j])
          return false;
      }
    }
    return true;
  }
};
