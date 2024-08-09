class Solution:
  def countInterestingSubarrays(self, nums: List[int], modulo: int, k: int) -> int:
    ans = 0
    prefix = 0  # (number of nums[i] % modulo == k so far) % modulo
    prefixCount = collections.Counter({0: 1})

    for num in nums:
      if num % modulo == k:
        prefix = (prefix + 1) % modulo
      ans += prefixCount[(prefix - k + modulo) % modulo]
      prefixCount[prefix] += 1

    return ans
