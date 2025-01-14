class Solution {
 public:
  int matrixSum(vector<vector<int>>& nums) {
    int ans = 0;

    for (vector<int>& row : nums)
      ranges::sort(row);

    for (int j = 0; j < nums[0].size(); ++j) {
      int mx = 0;
      for (int i = 0; i < nums.size(); ++i)
        mx = max(mx, nums[i][j]);
      ans += mx;
    }

    return ans;
  }
};
