class Solution:
  def maximumRobots(
      self,
      chargeTimes: list[int],
      runningCosts: list[int],
      budget: int,
  ) -> int:
    cost = 0
    maxQ = collections.deque()  # Stores `chargeTimes[i]`.

    j = 0  # window's range := [i..j], so k = i - j + 1
    for i, (chargeTime, runningCost) in enumerate(
            zip(chargeTimes, runningCosts)):
      cost += runningCost
      while maxQ and maxQ[-1] < chargeTime:
        maxQ.pop()
      maxQ.append(chargeTime)
      if maxQ[0] + (i - j + 1) * cost > budget:
        if maxQ[0] == chargeTimes[j]:
          maxQ.popleft()
        cost -= runningCosts[j]
        j += 1

    return len(chargeTimes) - j
