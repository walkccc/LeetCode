class Solution {
  public int minPatches(int[] nums, int n) {
    int ans = 0;
    int i = 0;     // point to nums
    long miss = 1; // min sum in [1, n] we might miss

    while (miss <= n)
      if (i < nums.length && nums[i] <= miss) {
        miss += nums[i++];
      } else {
        // greedily add miss itself to increase the range
        // from [1, miss) to [1, 2 * miss)
        miss += miss;
        ++ans;
      }

    return ans;
  }
}
