class Solution {
 public:
  vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
    if (nums.empty() || r * c != nums.size() * nums[0].size())
      return nums;

    vector<vector<int>> ans(r, vector<int>(c));
    int k = 0;

    for (const vector<int>& row : nums)
      for (const int num : row) {
        ans[k / c][k % c] = num;
        ++k;
      }

    return ans;
  }
};
