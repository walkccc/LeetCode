class Solution:
  def numberOfSubstrings(self, s: str, k: int) -> int:
    n = len(s)
    ans = n * (n + 1) // 2
    count = collections.Counter()

    l = 0
    for r, c in enumerate(s):
      count[c] += 1
      while count[c] == k:
        count[s[l]] -= 1
        l += 1
      ans -= r - l + 1

    return ans
