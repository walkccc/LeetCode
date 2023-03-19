class Solution {
 public:
  int countMaxOrSubsets(vector<int>& nums) {
    const int ors = accumulate(begin(nums), end(nums), 0, bit_or<>());
    int ans = 0;
    dfs(nums, 0, 0, ors, ans);
    return ans;
  }

 private:
  void dfs(const vector<int>& nums, int i, int path, const int& ors, int& ans) {
    if (i == nums.size()) {
      if (path == ors)
        ++ans;
      return;
    }

    dfs(nums, i + 1, path, ors, ans);
    dfs(nums, i + 1, path | nums[i], ors, ans);
  }
};
