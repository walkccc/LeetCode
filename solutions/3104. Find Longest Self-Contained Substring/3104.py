class Solution:
  def maxSubstringLength(self, s: str) -> int:
    allCount = collections.Counter(s)

    # Similar to 395. Longest Substring with At Least K Repeating Characters
    def maxSubstringLengthWithNUniqueLetters(n: int) -> int:
      res = -1
      # the number of unique letters
      uniqueLetters = 0
      # the number of letters that have all their frequency in the substring
      lettersHavingAllFreq = 0
      count = collections.Counter()

      l = 0
      for r, c in enumerate(s):
        count[c] += 1
        if count[c] == 1:
          uniqueLetters += 1
        if count[c] == allCount[c]:
          lettersHavingAllFreq += 1
        while uniqueLetters > n:
          if count[s[l]] == allCount[s[l]]:
            lettersHavingAllFreq -= 1
          count[s[l]] -= 1
          if count[s[l]] == 0:
            uniqueLetters -= 1
          l += 1
        # Since both the number of unique letters and the number of letters
        # having all their frequency are equal to n, this is a valid window.
        # Implcit: uniqueLetters == n
        if lettersHavingAllFreq == n and r - l + 1 < len(s):
          res = max(res, r - l + 1)

      return res

    return max(maxSubstringLengthWithNUniqueLetters(n)
               for n in range(1, 27))
