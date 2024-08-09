class Solution {
 public:
  long long continuousSubarrays(vector<int>& nums) {
    long ans = 1;  // [nums[0]]
    int left = nums[0] - 2;
    int right = nums[0] + 2;
    int l = 0;

    // nums[l..r] is a valid window with range in [left, right].
    for (int r = 1; r < nums.size(); r++) {
      if (left <= nums[r] && nums[r] <= right) {
        left = max(left, nums[r] - 2);
        right = min(right, nums[r] + 2);
      } else {
        // nums[r] is out-of-bounds, so reconstruct the window.
        left = nums[r] - 2;
        right = nums[r] + 2;
        l = r;
        // If we consistently move leftward in each iteration, it implies that
        // the entire left subarray satisfies the given condition. For every
        // subarray with l in the range [0, r], the condition is met, preventing
        // the code from reaching the final "else" condition. Instead, it stops
        // at the "if" condition.
        while (nums[r] - 2 <= nums[l] && nums[l] <= nums[r] + 2) {
          left = max(left, nums[l] - 2);
          right = min(right, nums[l] + 2);
          --l;
        }
        ++l;
      }
      // nums[l..r], nums[l + 1..r], ..., nums[r]
      ans += r - l + 1;
    }

    return ans;
  }
};
