class Solution:
  def smallestDivisor(self, nums: List[int], threshold: int) -> int:
    l = 1
    r = max(nums)

    while l < r:
      m = (l + r) // 2
      if sum((num - 1) // m + 1 for num in nums) <= threshold:
        r = m
      else:
        l = m + 1

    return l
