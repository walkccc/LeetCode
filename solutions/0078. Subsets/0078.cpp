class Solution {
 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> path;

    function<void(int)> dfs = [&](int s) {
      ans.push_back(path);

      for (int i = s; i < nums.size(); ++i) {
        path.push_back(nums[i]);
        dfs(i + 1);
        path.pop_back();
      }
    };

    dfs(0);

    return ans;
  }
};