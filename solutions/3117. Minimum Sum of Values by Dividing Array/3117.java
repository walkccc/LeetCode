class Solution {
  public int minimumValueSum(int[] nums, int[] andValues) {
    Map<Integer, Integer>[][] mem = new Map[nums.length][andValues.length];
    Arrays.stream(mem).forEach(A -> Arrays.setAll(A, j -> new HashMap<>()));
    final int ans = minimumValueSum(nums, andValues, 0, 0, kAllMask, mem);
    return ans == kInf ? -1 : ans;
  }

  private static final int kInf = 1_000_000_000;
  private static final int kAllMask = (1 << 17) - 1;

  // Returns the minimum value sum of nums[i..n) and andValues[j..m), where
  // `mask` is the running value of the current subarray.
  private int minimumValueSum(int[] nums, int[] andValues, int i, int j, int mask,
                              Map<Integer, Integer>[][] mem) {
    if (i == nums.length && j == andValues.length)
      return 0;
    if (i == nums.length || j == andValues.length)
      return kInf;
    if (mem[i][j].containsKey(mask))
      return mem[i][j].get(mask);
    mask &= nums[i];
    if (mask < andValues[j]) {
      mem[i][j].put(mask, kInf);
      return kInf;
    }
    if (mask == andValues[j]) {
      // 1. Keep going.
      // 2. End the subarray here and pick nums[i], then fresh start.
      final int res =
          Math.min(minimumValueSum(nums, andValues, i + 1, j, mask, mem),
                   nums[i] + minimumValueSum(nums, andValues, i + 1, j + 1, kAllMask, mem));
      mem[i][j].put(mask, res);
      return res;
    }
    // Keep going.
    final int res = minimumValueSum(nums, andValues, i + 1, j, mask, mem);
    mem[i][j].put(mask, res);
    return res;
  }
}
