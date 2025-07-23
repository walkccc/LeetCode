class Solution:
  def findMinimumTime(self, strength: list[int]) -> int:
    costs = [[(s + turn - 1) // turn
             for s in strength]
             for turn in range(1, len(strength) + 1)]
    return self._hungarian(costs)[-1]

  def _hungarian(self, costs):
    """
    Returns an array `res` of length n (costs.length), with `res[i]` equaling
    the minimum cost to assign the first (i + 1) turns to the first (i + 1)
    locks using Hungarian algorithm, where costs[i][j] is the energy required
    to break j-th lock in i-th turn.

    https://en.wikipedia.org/wiki/Hungarian_algorithm
    """
    numLocks = len(costs)
    turnPotentials = [0] * numLocks
    lockPotentials = [0] * (numLocks + 1)
    lockAssignments = [-1] * (numLocks + 1)
    res = []

    for currentTurn in range(numLocks):
      currentLock = numLocks
      lockAssignments[currentLock] = currentTurn
      minReducedCosts = [math.inf] * (numLocks + 1)
      previousLockAssignments = [-1] * (numLocks + 1)
      locksInOptimalPath = [False] * (numLocks + 1)

      while lockAssignments[currentLock] != -1:
        locksInOptimalPath[currentLock] = True
        assignedTurn = lockAssignments[currentLock]
        minCostDelta = math.inf
        nextLock = None

        for lock in range(numLocks):
          if not locksInOptimalPath[lock]:
            reducedCost = (
                costs[assignedTurn][lock] -
                turnPotentials[assignedTurn] -
                lockPotentials[lock]
            )
            oldMin = minReducedCosts[lock]
            minReducedCosts[lock] = min(oldMin, reducedCost)
            if minReducedCosts[lock] < oldMin:
              previousLockAssignments[lock] = currentLock
            if minReducedCosts[lock] < minCostDelta:
              minCostDelta = minReducedCosts[lock]
              nextLock = lock

        for lock in range(numLocks + 1):
          if locksInOptimalPath[lock]:
            turnPotentials[lockAssignments[lock]] += minCostDelta
            lockPotentials[lock] -= minCostDelta
          else:
            minReducedCosts[lock] -= minCostDelta

        currentLock = nextLock

      while currentLock != numLocks:
        lockAssignments[currentLock] = lockAssignments[previousLockAssignments[currentLock]]
        currentLock = previousLockAssignments[currentLock]

      res.append(-lockPotentials[numLocks])

    return res
