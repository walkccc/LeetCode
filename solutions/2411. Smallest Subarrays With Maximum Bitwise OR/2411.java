class Solution {
  public int[] smallestSubarrays(int[] nums) {
    final int kMaxDigit = 30;
    int[] ans = new int[nums.length];
    // closest[j] := closest index i s.t. j-th bit of nums[i] is 1
    int[] closest = new int[kMaxDigit];

    Arrays.fill(ans, 1);

    for (int i = nums.length - 1; i >= 0; --i)
      for (int j = 0; j < kMaxDigit; ++j) {
        if ((nums[i] >> j & 1) == 1)
          closest[j] = i;
        ans[i] = Math.max(ans[i], closest[j] - i + 1);
      }

    return ans;
  }
}
