class Solution {
 public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    ranges::sort(candidates);
    dfs(candidates, 0, target, {}, ans);
    return ans;
  }

 private:
  void dfs(const vector<int>& candidates, int s, int target, vector<int>&& path,
           vector<vector<int>>& ans) {
    if (target < 0)
      return;
    if (target == 0) {
      ans.push_back(path);
      return;
    }

    for (int i = s; i < candidates.size(); ++i) {
      if (i > s && candidates[i] == candidates[i - 1])
        continue;
      path.push_back(candidates[i]);
      dfs(candidates, i + 1, target - candidates[i], std::move(path), ans);
      path.pop_back();
    }
  }
};
