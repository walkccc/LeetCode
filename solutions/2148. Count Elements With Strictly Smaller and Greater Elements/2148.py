class Solution:
  def countElements(self, nums: List[int]) -> int:
    mini = min(nums)
    maxi = max(nums)
    return sum(mini < num < maxi for num in nums)
