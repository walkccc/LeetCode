class Solution:
  def beautifulSubarrays(self, nums: List[int]) -> int:
    # A subarray is beautiful if xor(subarray) = 0.
    ans = 0
    prefix = 0
    prefixCount = collections.Counter({0: 1})

    for num in nums:
      prefix ^= num
      ans += prefixCount[prefix]
      prefixCount[prefix] += 1

    return ans
