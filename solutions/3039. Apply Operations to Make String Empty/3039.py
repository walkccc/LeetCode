class Solution:
  def lastNonEmptyString(self, s: str) -> str:
    ans = []
    count = collections.Counter(s)
    maxFreq = max(count.values())

    for c in reversed(s):
      if count[c] == maxFreq:
        ans.append(c)
        count[c] -= 1

    return ''.join(reversed(ans))
