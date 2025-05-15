class Solution:
  def minimumPairRemoval(self, nums: list[int]) -> int:
    ans = 0

    while any(x > y for x, y in itertools.pairwise(nums)):
      pairSums = [x + y for x, y in itertools.pairwise(nums)]
      minPairSum = min(pairSums)
      minPairIndex = pairSums.index(minPairSum)
      nums[minPairIndex] = minPairSum
      nums.pop(minPairIndex + 1)
      ans += 1

    return ans
