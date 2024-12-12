class Solution:
  def numberOfGoodPartitions(self, nums: list[int]) -> int:
    kMod = 1_000_000_007
    ans = 1
    # lastSeen[num] := the index of the last time `num` appeared
    lastSeen = {}

    for i, num in enumerate(nums):
      lastSeen[num] = i

    # Track the maximum right index of each running partition by ensuring that
    # the first and last occurrences of a number fall within the same partition.
    maxRight = 0
    for i, num in enumerate(nums):
      if i > maxRight:
        # Start a new partition that starts from nums[i].
        # Each partition doubles the total number of good partitions.
        ans = ans * 2 % kMod
      maxRight = max(maxRight, lastSeen[num])

    return ans
