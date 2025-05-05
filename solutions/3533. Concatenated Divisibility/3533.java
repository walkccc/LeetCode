class Solution {
  public int[] concatenatedDivisibility(int[] nums, int k) {
    final int n = nums.length;
    int[] lengths = new int[n];
    int[] pows = new int[n];

    Arrays.sort(nums);

    for (int i = 0; i < n; ++i) {
      lengths[i] = String.valueOf(nums[i]).length();
      pows[i] = (int) Math.pow(10, lengths[i]) % k;
    }

    Integer[][] mem = new Integer[1 << n][k];
    return dp(nums, pows, mem, k, 0, 0) ? reconstruct(nums, pows, mem, k, 0, 0) : new int[0];
  }

  // Returns true if there is a way to form a number divisible by `k` using the
  // numbers in `nums`, where nums[i] is used iff `mask & (1 << i)`.
  private boolean dp(int[] nums, int[] pows, Integer[][] mem, int k, int mask, int mod) {
    if (mem[mask][mod] != null)
      return mem[mask][mod] == 1;
    if (mask == (1 << nums.length) - 1)
      return (mem[mask][mod] = mod == 0 ? 1 : 0) == 1;
    for (int i = 0; i < nums.length; ++i)
      if ((mask >> i & 1) == 0) {
        final int newMod = (mod * pows[i] + nums[i]) % k;
        if (dp(nums, pows, mem, k, mask | 1 << i, newMod))
          return (mem[mask][mod] = 1) == 1;
      }
    return (mem[mask][mod] = 0) == 1;
  }

  // Reconstructs the numbers that form a number divisible by `k` using the
  // numbers in `nums`, where nums[i] is used iff `mask & (1 << i)`.
  private int[] reconstruct(int[] nums, int[] pows, Integer[][] mem, int k, int mask, int mod) {
    for (int i = 0; i < nums.length; ++i)
      if ((mask >> i & 1) == 0) {
        final int newMod = (mod * pows[i] + nums[i]) % k;
        if (dp(nums, pows, mem, k, mask | 1 << i, newMod)) {
          int[] first = new int[] {nums[i]};
          int[] rest = reconstruct(nums, pows, mem, k, mask | 1 << i, newMod);
          int[] res = new int[first.length + rest.length];
          System.arraycopy(first, 0, res, 0, first.length);
          System.arraycopy(rest, 0, res, first.length, rest.length);
          return res;
        }
      }
    return new int[0];
  }
}
