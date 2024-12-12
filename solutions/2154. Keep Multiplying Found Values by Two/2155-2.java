class Solution {
  public int findFinalValue(int[] nums, int original) {
    boolean[] seen = new boolean[1001];

    for (final int num : nums)
      seen[num] = true;

    while (original < 1001 && seen[original])
      original *= 2;

    return original;
  }
}
