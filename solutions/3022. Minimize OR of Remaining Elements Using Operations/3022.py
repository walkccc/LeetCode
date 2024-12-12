class Solution:
  def minOrAfterOperations(self, nums: list[int], k: int) -> int:
    kMaxBit = 30
    ans = 0
    prefixMask = 0  # Grows like: 10000 -> 11000 -> ... -> 11111

    for i in range(kMaxBit, -1, -1):
      # Add the i-th bit to `prefixMask` and attempt to "turn off" the
      # currently added bit within k operations. If it's impossible, then we
      # add the i-th bit to the answer.
      prefixMask |= 1 << i
      if self._getMergeOps(nums, prefixMask, ans) > k:
        ans |= 1 << i

    return ans

  def _getMergeOps(self, nums: list[int], prefixMask: int, target: int) -> int:
    """
    Returns the number of merge operations to turn `prefixMask` to the target
    by ANDing `nums`.
    """
    mergeOps = 0
    ands = prefixMask
    for num in nums:
      ands &= num
      if (ands | target) == target:
        ands = prefixMask
      else:
        mergeOps += 1  # Keep merging the next num
    return mergeOps
