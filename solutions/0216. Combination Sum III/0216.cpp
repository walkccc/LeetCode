class Solution {
 public:
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ans;
    vector<int> path;

    function<void(int, int, int)> dfs = [&](int k, int n, int s) {
      if (k == 0 && n == 0) {
        ans.push_back(path);
        return;
      }
      if (k == 0 || n <= 0) return;

      for (int i = s; i <= 9; ++i) {
        path.push_back(i);
        dfs(k - 1, n - i, i + 1);
        path.pop_back();
      }
    };

    dfs(k, n, 1);

    return ans;
  }
};