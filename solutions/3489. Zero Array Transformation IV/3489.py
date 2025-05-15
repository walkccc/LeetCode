class Solution:
  def minZeroArray(self, nums: list[int], queries: list[list[int]]) -> int:
    if all(num == 0 for num in nums):
      return 0

    n = len(nums)
    subsetSums = [{0} for _ in range(n)]

    for k, (l, r, val) in enumerate(queries):
      for i in range(l, r + 1):
        newSums = {subsetSum + val for subsetSum in subsetSums[i]}
        subsetSums[i].update(newSums)
      if all(nums[i] in subsetSums[i] for i in range(n)):
        return k + 1

    return -1
