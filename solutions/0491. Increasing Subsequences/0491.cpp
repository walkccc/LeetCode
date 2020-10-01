class Solution {
 public:
  vector<vector<int>> findSubsequences(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> path;

    function<void(int)> dfs = [&](int s) {
      if (path.size() > 1) ans.push_back(path);

      unordered_set<int> used;

      for (int i = s; i < nums.size(); ++i) {
        if (used.count(nums[i])) continue;
        if (path.empty() || nums[i] >= path.back()) {
          used.insert(nums[i]);
          path.push_back(nums[i]);
          dfs(i + 1);
          path.pop_back();
        }
      }
    };

    dfs(0);

    return ans;
  }
};