class Solution:
  def isOneEditDistance(self, s: str, t: str) -> bool:
    m = len(s)
    n = len(t)
    if m > n:  # make sure len(s) <= len(t)
      return self.isOneEditDistance(t, s)

    for i in range(m):
      if s[i] != t[i]:
        if m == n:
          return s[i + 1:] == t[i + 1:]  # replace s[i] with t[i]
        return s[i:] == t[i + 1:]  # delete t[i]

    return m + 1 == n  # delete t[-1]
