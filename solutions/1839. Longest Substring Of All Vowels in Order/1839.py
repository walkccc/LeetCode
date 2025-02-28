class Solution:
  def longestBeautifulSubstring(self, word: str) -> int:
    ans = 0
    count = 1

    l = 0
    for r in range(1, len(word)):
      curr = word[r]
      prev = word[r - 1]
      if curr >= prev:
        if curr > prev:
          count += 1
        if count == 5:
          ans = max(ans, r - l + 1)
      else:
        count = 1
        l = r

    return ans
