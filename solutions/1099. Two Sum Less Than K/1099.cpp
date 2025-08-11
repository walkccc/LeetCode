class Solution {
 public:
  int twoSumLessThanK(vector<int>& nums, int k) {
    if (nums.size() < 2)
      return -1;

    int ans = -1;  // Note the constraint that nums[i] > 0.
    int l = 0;
    int r = nums.size() - 1;

    ranges::sort(nums);

    while (l < r)
      if (nums[l] + nums[r] < k) {
        ans = max(ans, nums[l] + nums[r]);
        ++l;
      } else {
        --r;
      }

    return ans;
  }
};
