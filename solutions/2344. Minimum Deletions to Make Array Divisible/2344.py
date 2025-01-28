class Solution:
  def minOperations(self, nums: list[int], numsDivide: list[int]) -> int:
    gcd = functools.reduce(math.gcd, numsDivide)

    for i, num in enumerate(sorted(nums)):
      if gcd % num == 0:
        return i

    return -1
