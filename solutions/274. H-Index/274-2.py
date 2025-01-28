class Solution:
  def hIndex(self, citations: list[int]) -> int:
    n = len(citations)

    citations.sort()

    for i, citation in enumerate(citations):
      if citation >= n - i:
        return n - i

    return 0
