class Solution:
  def leftRigthDifference(self, nums: List[int]) -> List[int]:
    n = len(nums)
    leftSum = [0] * n
    rightSum = [0] * n
    prefix = 0
    suffix = 0

    for i in range(n):
      if i > 0:
        prefix += nums[i - 1]
      leftSum[i] = prefix

    for i in range(n - 1, -1, -1):
      if i + 1 < n:
        suffix += nums[i + 1]
      rightSum[i] = suffix

    return [abs(l - r) for l, r in zip(leftSum, rightSum)]
