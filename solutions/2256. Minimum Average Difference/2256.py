class Solution:
  def minimumAverageDifference(self, nums: list[int]) -> int:
    n = len(nums)
    ans = 0
    minDiff = inf
    prefix = 0
    suffix = sum(nums)

    for i, num in enumerate(nums):
      prefix += num
      suffix -= num
      prefixAvg = prefix // (i + 1)
      suffixAvg = 0 if i == n - 1 else suffix // (n - 1 - i)
      diff = abs(prefixAvg - suffixAvg)
      if diff < minDiff:
        ans = i
        minDiff = diff

    return ans
