class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    if (nums.size() < 3)
      return {};

    vector<vector<int>> ans;

    sort(begin(nums), end(nums));

    for (int i = 0; i + 2 < nums.size(); ++i) {
      if (i > 0 && nums[i] == nums[i - 1])
        continue;
      // choose nums[i] as the first num in the triplet,
      // and search the remaining nums in [i + 1, n - 1]
      int l = i + 1;
      int r = nums.size() - 1;
      while (l < r) {
        const int sum = nums[i] + nums[l] + nums[r];
        if (sum == 0) {
          ans.push_back({nums[i], nums[l++], nums[r--]});
          while (l < r && nums[l] == nums[l - 1])
            ++l;
          while (l < r && nums[r] == nums[r + 1])
            --r;
        } else if (sum < 0) {
          ++l;
        } else {
          --r;
        }
      }
    }

    return ans;
  }
};
