class Solution {
 public:
  int maximumBeauty(vector<int>& nums, int k) {
    int ans = 0;

    ranges::sort(nums);

    for (int l = 0, r = 0; r < nums.size(); ++r) {
      while (nums[r] - nums[l] > 2 * k)
        ++l;
      ans = max(ans, r - l + 1);
    }

    return ans;
  }
};
