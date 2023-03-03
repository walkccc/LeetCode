class Solution:
  def maxNumOfMarkedIndices(self, nums: List[int]) -> int:
    nums.sort()

    l = 0
    r = len(nums) // 2 + 1

    def isPossible(m: int) -> bool:
      for i in range(m):
        if 2 * nums[i] > nums[-m + i]:
          return False
      return True

    while l < r:
      m = (l + r) // 2
      if isPossible(m):
        l = m + 1
      else:
        r = m

    return (l - 1) * 2
