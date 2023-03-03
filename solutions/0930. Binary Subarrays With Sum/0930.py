class Solution:
  def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
    ans = 0
    prefix = 0
    count = collections.Counter({0: 1})

    for num in nums:
      prefix += num
      ans += count[prefix - goal]
      count[prefix] += 1

    return ans
