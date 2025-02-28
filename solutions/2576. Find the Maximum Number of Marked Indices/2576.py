class Solution:
  def maxNumOfMarkedIndices(self, nums: list[int]) -> int:
    nums.sort()

    def isPossible(m: int) -> bool:
      for i in range(m):
        if 2 * nums[i] > nums[-m + i]:
          return False
      return True

    l = bisect.bisect_left(range(len(nums) // 2 + 1), True,
                           key=lambda m: not isPossible(m))
    return (l - 1) * 2
