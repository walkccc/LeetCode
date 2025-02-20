class Solution:
  def countCollisions(self, directions: str) -> int:
    l = 0
    r = len(directions) - 1

    while l < len(directions) and directions[l] == 'L':
      l += 1

    while r >= 0 and directions[r] == 'R':
      r -= 1

    return sum(c != 'S' for c in directions[l:r + 1])
