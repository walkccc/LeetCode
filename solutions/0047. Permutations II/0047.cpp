class Solution {
 public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> path;
    vector<bool> used(nums.size(), false);

    function<void()> dfs = [&]() {
      if (path.size() == nums.size()) {
        ans.push_back(path);
        return;
      }

      for (int i = 0; i < nums.size(); ++i) {
        if (used[i]) continue;
        if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;
        used[i] = true;
        path.push_back(nums[i]);
        dfs();
        path.pop_back();
        used[i] = false;
      }
    };

    sort(begin(nums), end(nums));
    dfs();

    return ans;
  }
};