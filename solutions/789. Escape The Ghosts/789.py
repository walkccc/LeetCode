class Solution:
  def escapeGhosts(self, ghosts: List[List[int]], target: List[int]) -> bool:
    ghostSteps = min(abs(x - target[0]) +
                     abs(y - target[1]) for x, y in ghosts)

    return abs(target[0]) + abs(target[1]) < ghostSteps
