class Solution {
  public int getMaxLen(int[] nums) {
    int ans = 0;
    // the maximum length of subarrays ending in `num` with a negative product
    int neg = 0;
    // the maximum length of subarrays ending in `num` with a positive product
    int pos = 0;

    for (final int num : nums) {
      pos = num == 0 ? 0 : pos + 1;
      neg = num == 0 || neg == 0 ? 0 : neg + 1;
      if (num < 0) {
        final int temp = pos;
        pos = neg;
        neg = temp;
      }
      ans = Math.max(ans, pos);
    }

    return ans;
  }
}
