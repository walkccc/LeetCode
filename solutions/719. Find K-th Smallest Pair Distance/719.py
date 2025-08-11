class Solution:
  def smallestDistancePair(self, nums: list[int], k: int) -> int:
    nums.sort()

    def numPairDistancesNoGreaterThan(m: int) -> int:
      count = 0
      j = 1
      # For each index i, find the first index j s.t. nums[j] > nums[i] + m,
      # so numPairDistancesNoGreaterThan for the index i will be j - i - 1.
      for i, num in enumerate(nums):
        while j < len(nums) and nums[j] <= num + m:
          j += 1
        count += j - i - 1
      return count

    return bisect.bisect_left(range(nums[-1] - nums[0]), k,
                              key=numPairDistancesNoGreaterThan)
