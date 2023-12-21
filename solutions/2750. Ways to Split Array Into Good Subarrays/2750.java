class Solution {
  public int numberOfGoodSubarraySplits(int[] nums) {
    if (Arrays.stream(nums).filter(num -> num == 1).count() == 0)
      return 0;

    final int kMod = 1_000_000_007;
    int prev = -1; // the previous index of 1
    int ans = 1;

    for (int i = 0; i < nums.length; ++i)
      if (nums[i] == 1) {
        if (prev != -1)
          ans = (int) ((long) ans * (i - prev) % kMod);
        prev = i;
      }

    return ans;
  }
}
