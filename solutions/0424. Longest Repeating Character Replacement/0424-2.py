class Solution:
  def characterReplacement(self, s: str, k: int) -> int:
    ans = 0
    maxCount = 0
    count = collections.Counter()

    # l and r track max window instead of valid window.
    l = 0
    for r, c in enumerate(s):
      count[c] += 1
      maxCount = max(maxCount, count[c])
      while maxCount + k < r - l + 1:
        count[s[l]] -= 1
        l += 1

    return r - l + 1
