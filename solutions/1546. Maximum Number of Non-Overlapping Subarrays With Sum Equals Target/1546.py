class Solution:
  def maxNonOverlapping(self, nums: list[int], target: int) -> int:
    # Ending the subarray ASAP always has a better result.
    ans = 0
    prefix = 0
    prefixes = {0}

    # Greedily find the subarrays that equal to the target.
    for num in nums:
      # Check if there is a subarray ends in here and equals to the target.
      prefix += num
      if prefix - target in prefixes:
        # Find one and discard all the prefixes that have been used.
        ans += 1
        prefix = 0
        prefixes = {0}
      else:
        prefixes.add(prefix)

    return ans
