class Solution:
  def minimumDeletions(self, nums: List[int]) -> int:
    n = len(nums)
    a = nums.index(min(nums))
    b = nums.index(max(nums))
    if a > b:
      a, b = b, a
    return min(a + 1 + n - b, b + 1, n - a)
