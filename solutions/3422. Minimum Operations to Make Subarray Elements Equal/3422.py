class Solution:
  def minOperations(self, nums: list[int], k: int) -> int:
    window = SortedList(nums[:k])
    median = window[(k - 1) // 2]
    ops = sum(abs(median - nums[j]) for j in range(k))
    ans = ops

    for i in range(k, len(nums)):
      window.remove(nums[i - k])
      window.add(nums[i])
      ops -= abs(median - nums[i - k])
      ops += abs(median - nums[i])
      newMedian = window[(k - 1) // 2]
      medianMultiplier = (
          2
          if k % 2 == 0 and median <= newMedian <= window[k // 2]
          else k % 2)
      ops -= abs(newMedian - median) * medianMultiplier
      median = newMedian
      ans = min(ans, ops)

    return ans
