class Solution:
  def getLengthOfOptimalCompression(self, s: str, k: int) -> int:
    def getLength(maxFreq: int) -> int:
      """Returns the length to compress `maxFreq`."""
      if maxFreq == 1:
        return 1  # c
      if maxFreq < 10:
        return 2  # [1-9]c
      if maxFreq < 100:
        return 3  # [1-9][0-9]c
      return 4    # [1-9][0-9][0-9]c

    @functools.lru_cache(None)
    def dp(i: int, k: int) -> int:
      """Returns the length of optimal dp of s[i..n) with at most k deletion."""
      if k < 0:
        return math.inf
      if i == len(s) or len(s) - i <= k:
        return 0

      ans = math.inf
      maxFreq = 0  # the maximum frequency in s[i..j]
      count = collections.Counter()

      # Make letters in s[i..j] be the same.
      # Keep the letter that has the maximum frequency in this range and remove
      # the other letters.
      for j in range(i, len(s)):
        count[s[j]] += 1
        maxFreq = max(maxFreq, count[s[j]])
        ans = min(ans, getLength(maxFreq) +
                  dp(j + 1, k - (j - i + 1 - maxFreq)))

      return ans

    return dp(0, k)
