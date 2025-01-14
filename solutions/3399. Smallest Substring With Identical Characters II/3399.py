class Solution:
  # Same as 3398. Smallest Substring With Identical Characters I
  def minLength(self, s: str, numOps: int) -> int:
    def getMinOps(k: int) -> int:
      """
      Returns the minimum number of operations needed to make all groups of
      identical characters of length k or less.
      """
      if k == 1:
        res = sum(1 for i, c in enumerate(s) if int(c) == i % 2)
        return min(res, len(s) - res)

      res = 0
      runningLen = 1

      for a, b in itertools.pairwise(s):
        if a == b:
          runningLen += 1
        else:
          res += runningLen // (k + 1)
          runningLen = 1

      return res + runningLen // (k + 1)

    return bisect_left(range(1, len(s) + 1),
                       True, key=lambda m: getMinOps(m) <= numOps)
