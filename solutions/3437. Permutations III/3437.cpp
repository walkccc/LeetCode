class Solution {
 public:
  vector<vector<int>> permute(int n) {
    vector<vector<int>> ans;
    dfs(n, vector<bool>(n + 1), {}, ans);
    return ans;
  }

 private:
  void dfs(int n, vector<bool>&& used, vector<int>&& path,
           vector<vector<int>>& ans) {
    if (path.size() == n) {
      ans.push_back(path);
      return;
    }
    for (int num = 1; num <= n; ++num) {
      if (used[num])
        continue;
      if (!path.empty() && path.back() % 2 == num % 2)
        continue;
      used[num] = true;
      path.push_back(num);
      dfs(n, std::move(used), std::move(path), ans);
      path.pop_back();
      used[num] = false;
    }
  }
};
