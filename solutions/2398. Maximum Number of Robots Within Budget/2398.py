class Solution:
  def maximumRobots(self, chargeTimes: List[int], runningCosts: List[int], budget: int) -> int:
    cost = 0
    q = deque()  # max queue storing chargeTimes[i]

    j = 0  # window's range := [i..j], so k = i - j + 1
    for i, (chargeTime, runningCost) in enumerate(zip(chargeTimes, runningCosts)):
      cost += runningCost
      while q and q[-1] < chargeTime:
        q.pop()
      q.append(chargeTime)
      if q[0] + (i - j + 1) * cost > budget:
        if q[0] == chargeTimes[j]:
          q.popleft()
        cost -= runningCosts[j]
        j += 1

    return len(chargeTimes) - j
