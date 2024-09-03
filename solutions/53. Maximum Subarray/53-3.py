from dataclasses import dataclass


@dataclass(frozen=True)
class T:
  # the sum of the subarray starting from the first number
  maxSubarraySumLeft: int
  # the sum of the subarray ending in the last number
  maxSubarraySumRight: int
  maxSubarraySum: int
  summ: int


class Solution:
  def maxSubArray(self, nums: list[int]) -> int:
    def divideAndConquer(l: int, r: int) -> T:
      if l == r:
        return T(nums[l], nums[l], nums[l], nums[l])

      m = (l + r) // 2
      t1 = divideAndConquer(l, m)
      t2 = divideAndConquer(m + 1, r)

      maxSubarraySumLeft = max(t1.maxSubarraySumLeft,
                               t1.summ + t2.maxSubarraySumLeft)
      maxSubarraySumRight = max(
          t1.maxSubarraySumRight + t2.summ, t2.maxSubarraySumRight)
      maxSubarraySum = max(t1.maxSubarraySumRight +
                           t2.maxSubarraySumLeft, t1.maxSubarraySum, t2.maxSubarraySum)
      summ = t1.summ + t2.summ
      return T(maxSubarraySumLeft, maxSubarraySumRight, maxSubarraySum, summ)

    return divideAndConquer(0, len(nums) - 1).maxSubarraySum
