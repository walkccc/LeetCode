class Solution:
  def maximumInvitations(self, grid: list[list[int]]) -> int:
    m = len(grid)
    n = len(grid[0])
    ans = 0
    mates = [-1] * n  # mates[i] := the i-th girl's mate

    def canInvite(i: int, seen: list[bool]) -> bool:
      """Returns True if the i-th boy can make an invitation."""
      # The i-th boy asks each girl.
      for j in range(n):
        if not grid[i][j] or seen[j]:
          continue
        seen[j] = True
        if mates[j] == -1 or canInvite(mates[j], seen):
          mates[j] = i  # Match the j-th girl with i-th boy.
          return True
      return False

    for i in range(m):
      seen = [False] * n
      if canInvite(i, seen):
        ans += 1

    return ans
