class Solution {
 public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    vector<int> path;

    function<void(int, int)> dfs = [&](int k, int s) {
      if (k == 0) {
        ans.push_back(path);
        return;
      }

      for (int i = s; i <= n; ++i) {
        path.push_back(i);
        dfs(k - 1, i + 1);
        path.pop_back();
      }
    };

    dfs(k, 1);

    return ans;
  }
};