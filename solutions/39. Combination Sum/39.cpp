class Solution {
 public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    ranges::sort(candidates);
    dfs(candidates, 0, target, {}, ans);
    return ans;
  }

 private:
  void dfs(const vector<int>& A, int s, int target, vector<int>&& path,
           vector<vector<int>>& ans) {
    if (target < 0)
      return;
    if (target == 0) {
      ans.push_back(path);
      return;
    }

    for (int i = s; i < A.size(); ++i) {
      path.push_back(A[i]);
      dfs(A, i, target - A[i], std::move(path), ans);
      path.pop_back();
    }
  }
};
