class Solution:
  def maxScore(self, nums: list[int]) -> int:
    n = len(nums)
    # prefixGcd[i] := GCD of nums[0..i]
    # prefixLcm[i] := LCM of nums[0..i]
    prefixGcd, prefixLcm = self._getPrefix(nums)
    # suffixGcd[i] := GCD of nums[i..n - 1]
    # suffixLcm[i] := LCM of nums[i..n - 1]
    suffixGcd, suffixLcm = self._getSuffix(nums)
    ans = suffixGcd[0] * suffixLcm[0]

    for i in range(n):
      gcd1 = prefixGcd[i - 1] if i > 0 else 0
      gcd2 = suffixGcd[i + 1] if i + 1 < n else 0
      lcm1 = prefixLcm[i - 1] if i > 0 else 1
      lcm2 = suffixLcm[i + 1] if i + 1 < n else 1
      score = math.gcd(gcd1, gcd2) * math.lcm(lcm1, lcm2)
      ans = max(ans, score)

    return ans

  def _getPrefix(self, nums: list[int]) -> tuple[list[int], list[int]]:
    """Returns the prefix GCD and LCM arrays."""
    prefixGcd = []
    prefixLcm = []
    currGcd = 0
    currLcm = 1
    for num in nums:
      currGcd = math.gcd(currGcd, num)
      currLcm = math.lcm(currLcm, num)
      prefixGcd.append(currGcd)
      prefixLcm.append(currLcm)
    return prefixGcd, prefixLcm

  def _getSuffix(self, nums: list[int]) -> tuple[list[int], list[int]]:
    """Returns the suffix GCD and LCM arrays."""
    suffixGcd = []
    suffixLcm = []
    currGcd = 0
    currLcm = 1
    for num in reversed(nums):
      currGcd = math.gcd(currGcd, num)
      currLcm = math.lcm(currLcm, num)
      suffixGcd.append(currGcd)
      suffixLcm.append(currLcm)
    return list(reversed(suffixGcd)), list(reversed(suffixLcm))
