class Solution:
  def isOneEditDistance(self, s: str, t: str) -> bool:
    m = len(s)
    n = len(t)
    if m > n:  # Make sure that |s| <= |t|.
      return self.isOneEditDistance(t, s)

    for i in range(m):
      if s[i] != t[i]:
        if m == n:
          return s[i + 1:] == t[i + 1:]  # Replace s[i] with t[i].
        return s[i:] == t[i + 1:]  # Delete t[i].

    return m + 1 == n  # Delete t[-1].
