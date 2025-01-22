class Solution {
 public:
  int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
    int ans = 0;
    int l = -1;
    int r = -1;

    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] > right)  // Handle the reset value.
        l = i;
      if (nums[i] >= left)  // Handle the reset and the needed value.
        r = i;
      ans += r - l;
    }

    return ans;
  }
};
