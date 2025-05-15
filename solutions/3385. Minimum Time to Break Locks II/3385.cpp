class Solution {
 public:
  int findMinimumTime(vector<int>& strength) {
    vector<vector<int>> costs;

    for (int turn = 1; turn <= strength.size(); ++turn) {
      vector<int> cost;
      for (const int s : strength)
        cost.push_back((s + turn - 1) / turn);
      costs.push_back(cost);
    }

    return hungarian(costs).back();
  }

 private:
  // Updates the currentMinimum if potentialMinimum is smaller and returns true.
  bool updateMinimum(int& currentMinimum, const int& potentialMinimum) {
    if (potentialMinimum < currentMinimum) {
      currentMinimum = potentialMinimum;
      return true;
    }
    return false;
  }

  // Returns an array `res` of length n (costs.length), with `res[i]` equaling
  // the minimum cost to assign the first (i + 1) turns to the first (i + 1)
  // locks using Hungarian algorithm, where costs[i][j] is the energy required
  // to break j-th lock in i-th turn.
  //
  // https://en.wikipedia.org/wiki/Hungarian_algorithm
  vector<int> hungarian(const vector<vector<int>>& costs) {
    const int numLocks = costs.size();
    vector<int> res;
    vector<int> lockAssignments(numLocks + 1, -1);
    vector<int> turnPotentials(numLocks);
    vector<int> lockPotentials(numLocks + 1);

    for (int currentTurn = 0; currentTurn < numLocks; ++currentTurn) {
      int currentLock = numLocks;
      lockAssignments[currentLock] = currentTurn;
      vector<int> minReducedCosts(numLocks + 1, INT_MAX);
      vector<int> previousLockAssignments(numLocks + 1, -1);
      vector<bool> locksInOptimalPath(numLocks + 1);

      while (lockAssignments[currentLock] != -1) {
        locksInOptimalPath[currentLock] = true;
        const int assignedTurn = lockAssignments[currentLock];
        int minCostDelta = INT_MAX;
        int nextLock;

        for (int lock = 0; lock < numLocks; ++lock)
          if (!locksInOptimalPath[lock]) {
            const int reducedCost = costs[assignedTurn][lock] -
                                    turnPotentials[assignedTurn] -
                                    lockPotentials[lock];
            if (updateMinimum(minReducedCosts[lock], reducedCost))
              previousLockAssignments[lock] = currentLock;
            if (updateMinimum(minCostDelta, minReducedCosts[lock]))
              nextLock = lock;
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
        lockAssignments[currentLock] =
            lockAssignments[lock = previousLockAssignments[currentLock]];

      res.push_back(-lockPotentials[numLocks]);
    }

    return res;
  }
};
