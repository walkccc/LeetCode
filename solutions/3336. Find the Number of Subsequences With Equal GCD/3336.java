class Solution {
  public int subsequencePairCount(int[] nums) {
    final int maxNum = Arrays.stream(nums).max().getAsInt();
    Integer[][][] mem = new Integer[nums.length][maxNum + 1][maxNum + 1];
    return subsequencePairCount(nums, 0, 0, 0, mem);
  }

  private static final int MOD = 1_000_000_007;

  private int subsequencePairCount(int[] nums, int i, int x, int y, Integer[][][] mem) {
    if (i == nums.length)
      return (x > 0 && x == y) ? 1 : 0;
    if (mem[i][x][y] != null)
      return mem[i][x][y];
    // 1. Skip nums[i]
    final int skip = subsequencePairCount(nums, i + 1, x, y, mem);
    // 2. Pick nums[i] in the first subsequence
    final int take1 = subsequencePairCount(nums, i + 1, gcd(x, nums[i]), y, mem);
    // 3. Pick nums[i] in the second subsequence
    final int take2 = subsequencePairCount(nums, i + 1, x, gcd(y, nums[i]), mem);
    return mem[i][x][y] = (int) (((long) skip + take1 + take2) % MOD);
  }

  private int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
  }
}
