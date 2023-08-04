class Solution:
  def maximumRobots(self, chargeTimes: List[int], runningCosts: List[int], budget: int) -> int:
    cost = 0
    dq = collections.deque()  # max queue storing chargeTimes[i]

    j = 0  # window's range := [i..j], so k = i - j + 1
    for i, (chargeTime, runningCost) in enumerate(zip(chargeTimes, runningCosts)):
      cost += runningCost
      while dq and dq[-1] < chargeTime:
        dq.pop()
      dq.append(chargeTime)
      if dq[0] + (i - j + 1) * cost > budget:
        if dq[0] == chargeTimes[j]:
          dq.popleft()
        cost -= runningCosts[j]
        j += 1

    return len(chargeTimes) - j
