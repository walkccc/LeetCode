class Solution {
 public:
  int triangleNumber(vector<int>& nums) {
    if (nums.size() < 3)
      return 0;

    int ans = 0;

    sort(begin(nums), end(nums));

    for (int k = nums.size() - 1; k > 1; --k) {
      int i = 0;
      int j = k - 1;
      while (i < j)
        if (nums[i] + nums[j] > nums[k]) {
          // (nums[i], nums[j], nums[k])
          // (nums[i + 1], nums[j], nums[k])
          // ...
          // (nums[j - 1], nums[j], nums[k])
          ans += j - i;
          --j;
        } else {
          ++i;
        }
    }

    return ans;
  }
};
