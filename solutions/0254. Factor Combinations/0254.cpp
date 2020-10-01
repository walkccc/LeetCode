class Solution {
 public:
  vector<vector<int>> getFactors(int n) {
    vector<vector<int>> ans;
    vector<int> path;

    function<void(int, int)> dfs = [&](int n, int s) {
      if (n <= 1) {
        if (path.size() > 1)
          ans.push_back(path);
        return;
      }

      for (int i = s; i <= n; ++i)
        if (n % i == 0) {
          path.push_back(i);
          dfs(n / i, i);
          path.pop_back();
        }
    };

    dfs(n, 2);  // the smallest factor is 2

    return ans;
  }
};