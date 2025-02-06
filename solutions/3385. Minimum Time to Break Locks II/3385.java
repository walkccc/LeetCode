class Solution {
  public int findMinimumTime(int[] strength) {
    int[][] costs = new int[strength.length][strength.length];
    for (int turn = 1; turn <= strength.length; ++turn)
      for (int j = 0; j < strength.length; j++)
        costs[turn - 1][j] = (strength[j] + turn - 1) / turn;
    return hungarian(costs)[costs.length - 1];
  }

  // Updates the currentMinimum if potentialMinimum is smaller and returns true.
  private boolean updateMinimum(int[] currentMinimum, int potentialMinimum, int index) {
    if (potentialMinimum < currentMinimum[index]) {
      currentMinimum[index] = potentialMinimum;
      return true;
    }
    return false;
  }

  // Returns an array `res` of length n (costs.length), with `res[i]` equaling
  // the minimum cost to assign the first (i + 1) turns to the first (i + 1)
  // locks using the Hungarian algorithm, where costs[i][j] is the energy required
  // to break j-th lock in i-th turn.
  //
  // https://en.wikipedia.org/wiki/Hungarian_algorithm
  private int[] hungarian(int[][] costs) {
    final int numLocks = costs.length;
    int[] res = new int[numLocks];
    int[] turnPotentials = new int[numLocks];
    int[] lockPotentials = new int[numLocks + 1];
    int[] lockAssignments = new int[numLocks + 1];
    Arrays.fill(lockAssignments, -1);

    for (int currentTurn = 0; currentTurn < numLocks; ++currentTurn) {
      int currentLock = numLocks;
      lockAssignments[currentLock] = currentTurn;
      int[] minReducedCosts = new int[numLocks + 1];
      Arrays.fill(minReducedCosts, Integer.MAX_VALUE);
      int[] previousLockAssignments = new int[numLocks + 1];
      boolean[] locksInOptimalPath = new boolean[numLocks + 1];

      while (lockAssignments[currentLock] != -1) {
        locksInOptimalPath[currentLock] = true;
        int assignedTurn = lockAssignments[currentLock];
        int minCostDelta = Integer.MAX_VALUE;
        int nextLock = -1;

        for (int lock = 0; lock < numLocks; ++lock)
          if (!locksInOptimalPath[lock]) {
            final int reducedCost =
                costs[assignedTurn][lock] - turnPotentials[assignedTurn] - lockPotentials[lock];
            if (updateMinimum(minReducedCosts, reducedCost, lock))
              previousLockAssignments[lock] = currentLock;
            if (minReducedCosts[lock] < minCostDelta) {
              minCostDelta = minReducedCosts[lock];
              nextLock = lock;
            }
          }

        for (int lock = 0; lock <= numLocks; ++lock)
          if (locksInOptimalPath[lock]) {
            turnPotentials[lockAssignments[lock]] += minCostDelta;
            lockPotentials[lock] -= minCostDelta;
          } else {
            minReducedCosts[lock] -= minCostDelta;
          }

        currentLock = nextLock;
      }

      for (int lock; currentLock != numLocks; currentLock = lock)
        lockAssignments[currentLock] = lockAssignments[lock = previousLockAssignments[currentLock]];

      res[currentTurn] = -lockPotentials[numLocks];
    }

    return res;
  }
}
