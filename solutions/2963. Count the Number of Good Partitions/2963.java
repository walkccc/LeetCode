class Solution {
  public int numberOfGoodPartitions(int[] nums) {
    final int kMod = 1_000_000_007;
    int ans = 1;

    // lastSeen[num] := the index of the last time `num` appeared
    HashMap<Integer, Integer> lastSeen = new HashMap<>();

    for (int i = 0; i < nums.length; ++i)
      lastSeen.put(nums[i], i);

    // Track the maximum right index of each running partition by ensuring that
    // the first and last occurrences of a number fall within the same
    // partition.
    int maxRight = 0;
    for (int i = 0; i < nums.length; ++i) {
      if (i > maxRight)
        // Start a new partition that starts from nums[i].
        // Each partition doubles the total number of good partitions.
        ans = (int) ((ans * 2L) % kMod);
      maxRight = Math.max(maxRight, lastSeen.get(nums[i]));
    }

    return ans;
  }
}
