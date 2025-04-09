class Solution {
  public int[] smallestSubarrays(int[] nums) {
    final int MAX_BIT = 30;
    int[] ans = new int[nums.length];
    // closest[j] := the closest index i s.t. the j-th bit of nums[i] is 1
    int[] closest = new int[MAX_BIT];

    Arrays.fill(ans, 1);

    for (int i = nums.length - 1; i >= 0; --i)
      for (int j = 0; j < MAX_BIT; ++j) {
        if ((nums[i] >> j & 1) == 1)
          closest[j] = i;
        ans[i] = Math.max(ans[i], closest[j] - i + 1);
      }

    return ans;
  }
}
