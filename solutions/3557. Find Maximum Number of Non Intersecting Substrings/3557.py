class Solution:
  def maxSubstrings(self, word: str) -> int:
    ans = 0
    firstSeen = {}

    for i, c in enumerate(word):
      if c not in firstSeen:
        firstSeen[c] = i
      elif i - firstSeen[c] + 1 >= 4:
        ans += 1
        firstSeen.clear()

    return ans
