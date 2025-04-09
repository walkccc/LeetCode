class Solution {
  public int maxScore(int[] nums) {
    final int n = nums.length / 2;
    int[][] mem = new int[n + 1][1 << (n * 2)];
    return maxScore(nums, 1, 0, mem);
  }

  // Returns the maximum score you can receive after performing the k to n
  // operations, where `mask` is the bitmask of the chosen numbers.
  private int maxScore(int[] nums, int k, int mask, int[][] mem) {
    if (k == mem.length)
      return 0;
    if (mem[k][mask] > 0)
      return mem[k][mask];

    for (int i = 0; i < nums.length; ++i)
      for (int j = i + 1; j < nums.length; ++j) {
        final int chosenMask = 1 << i | 1 << j;
        if ((mask & chosenMask) == 0)
          mem[k][mask] = Math.max(mem[k][mask], k * gcd(nums[i], nums[j]) +
                                                    maxScore(nums, k + 1, mask | chosenMask, mem));
      }

    return mem[k][mask];
  }

  private int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
  }
}
