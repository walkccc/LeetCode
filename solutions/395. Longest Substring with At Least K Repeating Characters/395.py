class Solution:
  def longestSubstring(self, s: str, k: int) -> int:
    def longestSubstringWithNUniqueLetters(n: int) -> int:
      res = 0
      uniqueLetters = 0  # the number of unique letters
      lettersHavingKFreq = 0  # the number of letters having frequency >= k
      count = collections.Counter()

      l = 0
      for r, c in enumerate(s):
        count[c] += 1
        if count[c] == 1:
          uniqueLetters += 1
        if count[c] == k:
          lettersHavingKFreq += 1
        while uniqueLetters > n:
          if count[s[l]] == k:
            lettersHavingKFreq -= 1
          count[s[l]] -= 1
          if count[s[l]] == 0:
            uniqueLetters -= 1
          l += 1
        # Since both the number of unique letters and the number of letters
        # having frequency >= k are equal to n, this is a valid window.
        if lettersHavingKFreq == n:  # Implicit: uniqueLetters == n
          res = max(res, r - l + 1)

      return res

    return max(longestSubstringWithNUniqueLetters(n)
               for n in range(1, 27))
