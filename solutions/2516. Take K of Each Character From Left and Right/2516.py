class Solution:
  def takeCharacters(self, s: str, k: int) -> int:
    n = len(s)
    ans = n
    count = collections.Counter(s)
    if any(count[c] < k for c in 'abc'):
      return -1

    l = 0
    for r, c in enumerate(s):
      count[c] -= 1
      while count[c] < k:
        count[s[l]] += 1
        l += 1
      ans = min(ans, n - (r - l + 1))

    return ans
