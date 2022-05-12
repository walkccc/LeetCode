class Solution:
  def equalCountSubstrings(self, s: str, count: int) -> int:
    maxUnique = len(set(s))
    ans = 0

    for unique in range(1, maxUnique + 1):
      windowSize = unique * count
      lettersCount = Counter()
      uniqueCount = 0
      for i, c in enumerate(s):
        lettersCount[c] += 1
        if lettersCount[c] == count:
          uniqueCount += 1
        if i >= windowSize:
          lettersCount[s[i - windowSize]] -= 1
          if lettersCount[s[i - windowSize]] == count - 1:
            uniqueCount -= 1
        ans += uniqueCount == unique

    return ans
