class Solution:
  def characterReplacement(self, s: str, k: int) -> int:
    ans = 0
    maxFreq = 0
    count = Counter()

    l = 0
    for r, c in enumerate(s):
      count[c] += 1
      maxFreq = max(maxFreq, count[c])
      while maxFreq + k < r - l + 1:
        count[s[l]] -= 1
        l += 1
      ans = max(ans, r - l + 1)

    return ans
