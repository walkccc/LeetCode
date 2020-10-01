class Solution {
 public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> path;

    function<void(int)> dfs = [&](int s) {
      ans.push_back(path);

      for (int i = s; i < nums.size(); ++i) {
        if (i > s && nums[i] == nums[i - 1]) continue;
        path.push_back(nums[i]);
        dfs(i + 1);
        path.pop_back();
      }
    };

    sort(begin(nums), end(nums));
    dfs(0);

    return ans;
  }
};