class Solution:
  def countPairs(self, nums: List[int], target: int) -> int:
    return sum(nums[i] + nums[j] < target
               for i in range(len(nums))
               for j in range(i + 1, len(nums)))
