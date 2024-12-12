class Solution:
  def maximumLengthSubstring(self, s: str) -> int:
    ans = 0
    count = collections.Counter()

    l = 0
    for r, c in enumerate(s):
      count[c] += 1
      while count[c] > 2:
        count[s[l]] -= 1
        l += 1
      ans = max(ans, r - l + 1)

    return ans
