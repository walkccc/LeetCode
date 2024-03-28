class Solution:
  def balancedString(self, s: str) -> int:
    ans = len(s)
    count = collections.Counter(s)
    j = 0

    for i, c in enumerate(s):
      count[c] -= 1
      while j < len(s) and all(count[c] <= len(s) // 4 for c in 'QWER'):
        ans = min(ans, i - j + 1)
        count[s[j]] += 1
        j += 1

    return ans
