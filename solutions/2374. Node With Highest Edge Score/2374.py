class Solution:
  def edgeScore(self, edges: List[int]) -> int:
    scores = [0] * len(edges)
    for i, edge in enumerate(edges):
      scores[edge] += i
    return scores.index(max(scores))
