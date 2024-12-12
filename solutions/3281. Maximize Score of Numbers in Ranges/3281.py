class Solution:
  def maxPossibleScore(self, start: list[int], d: int) -> int:
    def isPossible(m: int) -> bool:
      lastPick = start[0]
      for i in range(1, len(start)):
        if lastPick + m > start[i] + d:
          return False
        lastPick = max(lastPick + m, start[i])
      return True

    start.sort()

    maxScore = (start[-1] + d) - start[0] + 1
    l = bisect.bisect_left(range(maxScore), True,
                           key=lambda m: not isPossible(m))
    return l - 1
