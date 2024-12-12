from sortedcontainers import SortedSet


class Solution:
  def maximumTripletValue(self, nums: list[int]) -> int:
    ans = 0
    rightMax = [0] * len(nums)  # rightMax[i] := max(nums[i + 1..n))
    leftSortedSet = SortedSet([nums[0]])

    for i in range(len(nums) - 2, -1, -1):
      rightMax[i] = max(nums[i + 1], rightMax[i + 1])

    for j in range(1, len(nums) - 1):
      i = bisect.bisect_left(leftSortedSet, nums[j])
      if i > 0 and rightMax[j] > nums[j]:
        ans = max(ans, leftSortedSet[i - 1] - nums[j] + rightMax[j])
      leftSortedSet.add(nums[j])

    return ans
