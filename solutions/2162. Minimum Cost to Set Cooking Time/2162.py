class Solution:
  def minCostSetTime(
      self,
      startAt: int,
      moveCost: int,
      pushCost: int,
      targetSeconds: int,
  ) -> int:
    ans = math.inf
    mins = 99 if targetSeconds > 5999 else targetSeconds // 60
    secs = targetSeconds - mins * 60

    def getCost(mins: int, secs: int) -> int:
      cost = 0
      curr = str(startAt)
      for c in str(mins * 100 + secs):
        if c == curr:
          cost += pushCost
        else:
          cost += moveCost + pushCost
          curr = c
      return cost

    while secs < 100:
      ans = min(ans, getCost(mins, secs))
      mins -= 1
      secs += 60

    return ans
