class Solution:
  def hIndex(self, citations: List[int]) -> int:
    n = len(citations)
    return n - bisect.bisect_left(range(n), n,
                                  key=lambda m: citations[m] + m)
