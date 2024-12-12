class Solution:
  def getSum(self, nums: list[int]) -> int:
    def getSum(diff: int) -> int:
      """Returns the sum of all subarrays with a difference of `diff`."""
      res = nums[0]
      summ = nums[0]
      count = 1
      for prev, num in itertools.pairwise(nums):
        if num == prev + diff:
          count += 1
          summ += count * num
        else:
          count = 1
          summ = num
        res += summ
      return res

    return (getSum(1) + getSum(-1) - sum(nums)) % 1_000_000_007
