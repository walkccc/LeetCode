class Solution {
 public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> ans;
    ranges::sort(nums);
    dfs(nums, vector<bool>(nums.size()), {}, ans);
    return ans;
  }

 private:
  void dfs(const vector<int>& nums, vector<bool>&& used, vector<int>&& path,
           vector<vector<int>>& ans) {
    if (path.size() == nums.size()) {
      ans.push_back(path);
      return;
    }

    for (int i = 0; i < nums.size(); ++i) {
      if (used[i])
        continue;
      if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
        continue;
      used[i] = true;
      path.push_back(nums[i]);
      dfs(nums, std::move(used), std::move(path), ans);
      path.pop_back();
      used[i] = false;
    }
  }
};
