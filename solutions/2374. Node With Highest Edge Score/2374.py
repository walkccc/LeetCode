class Solution:
  def edgeScore(self, edges: list[int]) -> int:
    scores = [0] * len(edges)
    for i, edge in enumerate(edges):
      scores[edge] += i
    return scores.index(max(scores))
