class Solution:
  def arrayRankTransform(self, arr: list[int]) -> list[int]:
    rank = {}

    for a in sorted(arr):
      if a not in rank:
        rank[a] = len(rank) + 1

    return map(rank.get, arr)
