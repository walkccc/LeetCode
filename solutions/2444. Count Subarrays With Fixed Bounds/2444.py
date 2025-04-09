class Solution:
  def countSubarrays(self, nums: list[int], minK: int, maxK: int) -> int:
    ans = 0
    j = -1
    prevMinKIndex = -1
    prevMaxKIndex = -1

    for i, num in enumerate(nums):
      if num < minK or num > maxK:
        j = i
      if num == minK:
        prevMinKIndex = i
      if num == maxK:
        prevMaxKIndex = i
      # Any index k in [j + 1, min(prevMinKIndex, prevMaxKIndex)] can be the
      # start of the subarray s.t. nums[k..i] satisfies the conditions.
      ans += max(0, min(prevMinKIndex, prevMaxKIndex) - j)

    return ans
