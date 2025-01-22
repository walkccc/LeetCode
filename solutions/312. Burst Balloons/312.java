class Solution {
  public int maxCoins(int[] nums) {
    final int n = nums.length;
    int[][] mem = new int[n + 2][n + 2];
    int[] extendedNums = new int[n + 2];
    System.arraycopy(nums, 0, extendedNums, 1, n);
    extendedNums[0] = 1;
    extendedNums[n + 1] = 1;
    return maxCoins(extendedNums, 1, n, mem);
  }

  // Returns maxCoins(nums[i..j]).
  private int maxCoins(int[] nums, int i, int j, int[][] mem) {
    if (i > j)
      return 0;
    if (mem[i][j] > 0)
      return mem[i][j];

    for (int k = i; k <= j; ++k)
      mem[i][j] = Math.max(mem[i][j],                          //
                           maxCoins(nums, i, k - 1, mem) +     //
                               maxCoins(nums, k + 1, j, mem) + //
                               nums[i - 1] * nums[k] * nums[j + 1]);

    return mem[i][j];
  }
}
