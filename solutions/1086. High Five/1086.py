class Solution:
  def highFive(self, items: List[List[int]]) -> List[List[int]]:
    idToScores = collections.defaultdict(list)

    for id, score in items:
      heapq.heappush(idToScores[id], score)
      if len(idToScores[id]) > 5:
        heapq.heappop(idToScores[id])

    return [[id, sum(scores) // 5] for id, scores in sorted(idToScores.items())]
