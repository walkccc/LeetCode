class Solution {
 public:
  int threeSumSmaller(vector<int>& nums, int target) {
    if (nums.size() < 3)
      return 0;

    int ans = 0;

    ranges::sort(nums);

    for (int i = 0; i + 2 < nums.size(); ++i) {
      int l = i + 1;
      int r = nums.size() - 1;
      while (l < r)
        if (nums[i] + nums[l] + nums[r] < target) {
          // (nums[i], nums[l], nums[r])
          // (nums[i], nums[l], nums[r - 1])
          // ...,
          // (nums[i], nums[l], nums[l + 1])
          ans += r - l;
          ++l;
        } else {
          --r;
        }
    }

    return ans;
  }
};
