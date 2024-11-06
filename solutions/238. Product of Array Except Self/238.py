class Solution:
  def productExceptSelf(self, nums: list[int]) -> list[int]:
    n = len(nums)
    prefix = [1] * n  # prefix product
    suffix = [1] * n  # suffix product

    for i in range(1, n):
      prefix[i] = prefix[i - 1] * nums[i - 1]

    for i in reversed(range(n - 1)):
      suffix[i] = suffix[i + 1] * nums[i + 1]

    return [prefix[i] * suffix[i] for i in range(n)]
