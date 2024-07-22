class Solution:
  def longestContinuousSubstring(self, s: str) -> int:
    ans = 1
    runningLen = 1

    for a, b in zip(s, s[1:]):
      if ord(a) + 1 == ord(b):
        runningLen += 1
        ans = max(ans, runningLen)
      else:
        runningLen = 1

    return ans
