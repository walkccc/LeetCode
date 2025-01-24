class Solution {
 public:
  int maximumBeauty(vector<int>& nums, int k) {
    // l and r track the maximum window instead of the valid window.
    int l = 0;
    int r = 0;

    ranges::sort(nums);

    for (r = 0; r < nums.size(); ++r)
      if (nums[r] - nums[l] > 2 * k)
        ++l;

    return r - l;
  }
};
