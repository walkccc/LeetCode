from dataclasses import dataclass


@dataclass(frozen=True)
class T:
  summ: int
  # the sum of the subarray starting from the first number
  maxSubarraySumLeft: int
  # the sum of the subarray ending in the last number
  maxSubarraySumRight: int
  maxSubarraySum: int


class Solution:
  def maxSubArray(self, nums: list[int]) -> int:
    def divideAndConquer(l: int, r: int) -> T:
      if l == r:
        return T(nums[l], nums[l], nums[l], nums[l])
      m = (l + r) // 2
      left = divideAndConquer(l, m)
      right = divideAndConquer(m + 1, r)
      maxSubarraySumLeft = max(left.maxSubarraySumLeft,
                               left.summ + right.maxSubarraySumLeft)
      maxSubarraySumRight = max(
          left.maxSubarraySumRight + right.summ, right.maxSubarraySumRight)
      maxSubarraySum = max(left.maxSubarraySumRight + right.maxSubarraySumLeft,
                           left.maxSubarraySum, right.maxSubarraySum)
      summ = left.summ + right.summ
      return T(summ, maxSubarraySumLeft, maxSubarraySumRight, maxSubarraySum)

    return divideAndConquer(0, len(nums) - 1).maxSubarraySum
