class Solution:
  def hIndex(self, citations: list[int]) -> int:
    n = len(citations)
    return n - bisect.bisect_left(range(n), n,
                                  key=lambda m: citations[m] + m)
