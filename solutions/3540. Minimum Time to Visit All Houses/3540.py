

class Solution:
  def minTotalTime(
      self,
      forward: list[int],
      backward: list[int],
      queries: list[int]
  ) -> int:
    summ = sum(backward)
    ans = 0
    pos = 0
    prefixF = [0] + list(itertools.accumulate(forward))
    prefixB = list(itertools.accumulate(backward)) + [0]

    for q in queries:
      r = int(q < pos) * prefixF[-1] + prefixF[q] - prefixF[pos]
      l = int(q > pos) * summ + prefixB[pos] - prefixB[q]
      ans += min(l, r)
      pos = q

    return ans
