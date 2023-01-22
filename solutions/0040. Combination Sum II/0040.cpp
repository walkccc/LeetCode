class Solution {
 public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> ans;

    sort(begin(candidates), end(candidates));
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
      if (i > s && A[i] == A[i - 1])
        continue;
      path.push_back(A[i]);
      dfs(A, i + 1, target - A[i], move(path), ans);
      path.pop_back();
    }
  }
};
