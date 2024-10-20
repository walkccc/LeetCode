class Solution {
  public int minOperations(int[] nums) {
    int ans = 0;
    int target = 1;

    for (final int num : nums)
      if (num != target) {
        target ^= 1;
        ++ans;
      }

    return ans;
  }
}
