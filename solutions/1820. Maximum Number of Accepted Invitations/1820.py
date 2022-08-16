class Solution:
  def maximumInvitations(self, grid: List[List[int]]) -> int:
    m = len(grid)
    n = len(grid[0])
    ans = 0
    mate = [-1] * n  # girl's mate

    def canInvite(i, seen):
      for j in range(n):
        if not grid[i][j] or seen[j]:
          continue
        seen[j] = True
        if mate[j] == -1 or canInvite(mate[j], seen):
          mate[j] = i  # match girl j with boy i
          return True
      return False

    for i in range(m):
      seen = [False] * n
      if canInvite(i, seen):
        ans += 1

    return ans
