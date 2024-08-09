class Solution:
  def longestConsecutive(self, nums: List[int]) -> int:
    ans = 0
    seen = set(nums)

    for num in nums:
      # `num` is the start of a sequence.
      if num - 1 in seen:
        continue
      length = 0
      while num in seen:
        num += 1
        length += 1
      ans = max(ans, length)

    return ans
