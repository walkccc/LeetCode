class Solution:
  def numWays(self, s: str) -> int:
    kMod = 1_000_000_007
    ones = s.count('1')
    if ones % 3 != 0:
      return 0
    if ones == 0:
      n = len(s)
      return (n - 1) * (n - 2) // 2 % kMod

    s1End = -1
    s2Start = -1
    s2End = -1
    s3Start = -1
    onesSoFar = 0

    for i, c in enumerate(s):
      if c == '1':
        onesSoFar += 1
      if s1End == -1 and onesSoFar == ones // 3:
        s1End = i
      elif s2Start == -1 and onesSoFar == ones // 3 + 1:
        s2Start = i
      if s2End == -1 and onesSoFar == ones // 3 * 2:
        s2End = i
      elif s3Start == -1 and onesSoFar == ones // 3 * 2 + 1:
        s3Start = i

    return (s2Start - s1End) * (s3Start - s2End) % kMod
