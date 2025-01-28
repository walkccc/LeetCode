class Solution {
 public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> ans;
    ranges::sort(nums);
    dfs(nums, 0, {}, ans);
    return ans;
  }

 private:
  void dfs(const vector<int>& nums, int s, vector<int>&& path,
           vector<vector<int>>& ans) {
    ans.push_back(path);

    for (int i = s; i < nums.size(); ++i) {
      if (i > s && nums[i] == nums[i - 1])
        continue;
      path.push_back(nums[i]);
      dfs(nums, i + 1, std::move(path), ans);
      path.pop_back();
    }
  }
};
