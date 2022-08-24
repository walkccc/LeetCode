class Solution:
  def characterReplacement(self, s: str, k: int) -> int:
    ans = 0
    maxCount = 0
    count = Counter()

    l = 0
    for r, c in enumerate(s):
      count[c] += 1
      maxCount = max(maxCount, count[c])
      while maxCount + k < r - l + 1:
        count[s[l]] -= 1
        l += 1
      ans = max(ans, r - l + 1)

    return ans
