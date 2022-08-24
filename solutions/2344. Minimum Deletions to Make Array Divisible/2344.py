class Solution:
  def minOperations(self, nums: List[int], numsDivide: List[int]) -> int:
    gcd = reduce(math.gcd, numsDivide)

    for i, num in enumerate(sorted(nums)):
      if gcd % num == 0:
        return i

    return -1
