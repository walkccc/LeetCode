class Solution:
  def maxFreq(self, s: str, maxLetters: int, minSize: int, maxSize: int) -> int:
    # Greedily consider strings with `minSize`, so ignore `maxSize`.
    ans = 0
    letters = 0
    count = collections.Counter()
    substringCount = collections.Counter()

    l = 0
    for r, c in enumerate(s):
      count[c] += 1
      if count[c] == 1:
        letters += 1
      while letters > maxLetters or r - l + 1 > minSize:
        count[s[l]] -= 1
        if count[s[l]] == 0:
          letters -= 1
        l += 1
      if r - l + 1 == minSize:
        sub = s[l:l + minSize]
        substringCount[sub] += 1
        ans = max(ans, substringCount[sub])

    return ans
