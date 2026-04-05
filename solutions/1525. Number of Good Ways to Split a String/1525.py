class Solution:
  def numSplits(self, s: str) -> int:
    n = len(s)
    ans = 0
    seen = set()
    prefix = [0] * n
    suffix = [0] * n

    for i in range(n):
      seen.add(s[i])
      prefix[i] = len(seen)

    seen.clear()

    for i in reversed(range(n)):
      seen.add(s[i])
      suffix[i] = len(seen)

    for i in range(n - 1):
      if prefix[i] == suffix[i + 1]:
        ans += 1

    return ans
