class Solution:
  def maxSubarraySum(self, nums: list[int], k: int) -> int:
    ans = -math.inf
    prefix = 0
    # minPrefix[i % k] := the minimum prefix sum of the first i numbers
    minPrefix = [math.inf] * k
    minPrefix[k - 1] = 0

    for i, num in enumerate(nums):
      prefix += num
      ans = max(ans, prefix - minPrefix[i % k])
      minPrefix[i % k] = min(minPrefix[i % k], prefix)

    return ans
