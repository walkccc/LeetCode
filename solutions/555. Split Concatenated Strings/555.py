class Solution:
  def splitLoopedString(self, strs: list[str]) -> str:
    ans = ''
    sortedStrs = [max(s, s[::-1]) for s in strs]

    for i, sortedStr in enumerate(sortedStrs):
      for s in (sortedStr, sortedStr[::-1]):
        for j in range(len(s) + 1):
          ans = max(
              ans, s[j:] + ''.join(sortedStrs[i + 1:] + sortedStrs[:i]) + s[:j])

    return ans
