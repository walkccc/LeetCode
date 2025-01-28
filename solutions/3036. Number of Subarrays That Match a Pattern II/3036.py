class Solution:
  # Same as 3034. Number of Subarrays That Match a Pattern I
  def countMatchingSubarrays(self, nums: list[int], pattern: list[int]) -> int:
    def getNum(a: int, b: int) -> int:
      if a < b:
        return 1
      if a > b:
        return -1
      return 0

    numsPattern = [getNum(a, b) for a, b in itertools.pairwise(nums)]
    return self._kmp(numsPattern, pattern)

  def _kmp(self, nums: list[int], pattern: list[int]) -> int:
    """Returns the number of occurrences of the pattern in `nums`."""

    def getLPS(nums: list[int]) -> list[int]:
      """
      Returns the lps array, where lps[i] is the length of the longest prefix of
      nums[0..i] which is also a suffix of this substring.
      """
      lps = [0] * len(nums)
      j = 0
      for i in range(1, len(nums)):
        while j > 0 and nums[j] != nums[i]:
          j = lps[j - 1]
        if nums[i] == nums[j]:
          lps[i] = j + 1
          j += 1
      return lps

    lps = getLPS(pattern)
    res = 0
    i = 0  # s' index
    j = 0  # pattern's index
    while i < len(nums):
      if nums[i] == pattern[j]:
        i += 1
        j += 1
        if j == len(pattern):
          res += 1
          j = lps[j - 1]
      # Mismatch after j matches.
      elif j != 0:
          # Don't match lps[0..lps[j - 1]] since they will match anyway.
        j = lps[j - 1]
      else:
        i += 1
    return res
