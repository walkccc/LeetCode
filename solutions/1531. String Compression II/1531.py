class Solution:
  def getLengthOfOptimalCompression(self, s: str, k: int) -> int:
    def getLength(maxFreq):  # The length to compress `maxFreq`
      if maxFreq == 1:
        return 1  # C
      if maxFreq < 10:
        return 2  # [1-9]c
      if maxFreq < 100:
        return 3  # [1-9][0-9]c
      return 4    # [1-9][0-9][0-9]c

    # Compression(i, k) := length of optimal compression of s[i:] w/ at most k deletion
    @functools.lru_cache(None)
    def compression(i, k):
      if k < 0:
        return math.inf
      if i == len(s) or len(s) - i <= k:
        return 0

      ans = math.inf
      maxFreq = 0  # Max freq in s[i..j]
      count = collections.Counter()

      # Make chars in s[i..j] be same
      # Keep the char that has max freq in this range and remove other chars
      for j in range(i, len(s)):
        count[s[j]] += 1
        maxFreq = max(maxFreq, count[s[j]])
        ans = min(ans, getLength(maxFreq) +
                  compression(j + 1, k - (j - i + 1 - maxFreq)))

      return ans

    return compression(0, k)
