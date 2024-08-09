class Solution {
 public:
  vector<vector<int>> getFactors(int n) {
    vector<vector<int>> ans;
    dfs(n, 2, {}, ans);  // The minimum factor is 2.
    return ans;
  }

 private:
  void dfs(int n, int s, vector<int>&& path, vector<vector<int>>& ans) {
    if (n <= 1) {
      if (path.size() > 1)
        ans.push_back(path);
      return;
    }

    for (int i = s; i <= n; ++i)
      if (n % i == 0) {
        path.push_back(i);
        dfs(n / i, i, move(path), ans);
        path.pop_back();
      }
  }
};
