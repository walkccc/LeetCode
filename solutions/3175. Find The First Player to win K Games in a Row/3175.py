class Solution:
  # Similar to 1535. Find the Winner of an Array Game
  def findWinningPlayer(self, skills: list[int], k: int) -> int:
    ans = 0
    wins = 0

    i = 1
    while i < len(skills) and wins < k:
      if skills[i] > skills[ans]:
        ans = i
        wins = 1
      else:
        wins += 1
      i += 1

    return ans
