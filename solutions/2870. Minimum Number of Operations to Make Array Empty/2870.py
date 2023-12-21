class Solution:
  def minOperations(self, nums: List[int]) -> int:
    count = collections.Counter(nums)
    if 1 in count.values():
      return -1
    return sum((freq + 2) // 3 for freq in count.values())
