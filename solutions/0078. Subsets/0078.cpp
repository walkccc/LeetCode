class Solution {
 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> path;

    dfs(nums, 0, path, ans);

    return ans;
  }

 private:
  void dfs(const vector<int>& nums, int s, vector<int>& path,
           vector<vector<int>>& ans) {
    ans.push_back(path);

    for (int i = s; i < nums.size(); ++i) {
      path.push_back(nums[i]);
      dfs(nums, i + 1, path, ans);
      path.pop_back();
    }
  }
};
