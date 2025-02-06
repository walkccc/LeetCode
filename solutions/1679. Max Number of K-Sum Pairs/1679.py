class Solution:
  def maxOperations(self, nums: list[int], k: int) -> int:
    count = collections.Counter(nums)
    return sum(min(count[num], count[k - num])
               for num in count) // 2
