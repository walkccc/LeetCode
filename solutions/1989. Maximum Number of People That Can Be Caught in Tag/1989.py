class Solution:
  def catchMaximumAmountofPeople(self, team: List[int], dist: int) -> int:
    ans = 0
    i = 0  # 0s index
    j = 0  # 1s index

    while i < len(team) and j < len(team):
      if i + dist < j or team[i] != 0:
        # Find the next 0 that can be caught by 1.
        i += 1
      elif j + dist < i or team[j] != 1:
        # Find the next 1 that can catch 0.
        j += 1
      else:
        # team[j] catches team[i], so move both.
        ans += 1
        i += 1
        j += 1

    return ans
