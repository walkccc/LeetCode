class Solution:
  def minimizeMax(self, nums: List[int], p: int) -> int:
    nums.sort()

    def numPairs(maxDiff: int) -> int:
      """
      Returns the number of pairs that can be obtained if the difference between
      each pair <= `maxDiff`.
      """
      pairs = 0
      i = 1
      while i < len(nums):
        # Greedily pair nums[i] with nums[i - 1].
        if nums[i] - nums[i - 1] <= maxDiff:
          pairs += 1
          i += 2
        else:
          i += 1
      return pairs

    return bisect.bisect_left(
        range(0, nums[-1] - nums[0]), p,
        key=lambda m: numPairs(m))
