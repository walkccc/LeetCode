class Solution {
  public int[] findPermutation(int[] nums) {
    final int n = nums.length;
    int[][] mem = new int[n][1 << n];
    // bestPick[last][mask] := the best pick, where `last` is the last chosen
    // number and `mask` is the bitmask of the chosen numbers
    int[][] bestPick = new int[n][1 << n];

    // Choose 0 as perm[0] since the score function is cyclic.
    getScore(nums, /*last=*/0, /*mask=*/1, bestPick, mem);
    return construct(bestPick);
  }

  // Returns the minimum score, where `last` is the last chosen number and
  // `mask` is the bitmask of the chosen numbers.
  private int getScore(int[] nums, int last, int mask, int[][] bestPick, int[][] mem) {
    if (Integer.bitCount(mask) == nums.length)
      return Math.abs(last - nums[0]); // |perm[n - 1] - nums[perm[0]]|
    if (mem[last][mask] > 0)
      return mem[last][mask];

    int minScore = Integer.MAX_VALUE;
    for (int i = 1; i < nums.length; ++i) {
      if ((mask >> i & 1) == 1)
        continue;
      int nextMinScore = Math.abs(last - nums[i]) + getScore(nums, i, mask | 1 << i, bestPick, mem);
      if (nextMinScore < minScore) {
        minScore = nextMinScore;
        bestPick[last][mask] = i;
      }
    }

    return mem[last][mask] = minScore;
  }

  private int[] construct(int[][] bestPick) {
    int[] ans = new int[bestPick.length];
    int last = 0;
    int mask = 1;
    for (int i = 0; i < bestPick.length; ++i) {
      ans[i] = last;
      last = bestPick[last][mask];
      mask |= 1 << last;
    }
    return ans;
  }
}
