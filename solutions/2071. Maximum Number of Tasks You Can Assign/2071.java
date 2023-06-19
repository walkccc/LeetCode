class Solution {
  public int maxTaskAssign(int[] tasks, int[] workers, int pills, int strength) {
    int ans = 0;
    int l = 0;
    int r = Math.min(tasks.length, workers.length);

    Arrays.sort(tasks);
    Arrays.sort(workers);

    while (l <= r) {
      final int m = (l + r) / 2;
      if (canComplete(tasks, workers, pills, strength, m)) {
        ans = m;
        l = m + 1;

      } else {
        r = m - 1;
      }
    }

    return ans;
  }

  // Can we finish k tasks?
  private boolean canComplete(int[] tasks, int[] workers, int pillsLeft, int strength, int k) {
    // K strongest workers
    TreeMap<Integer, Integer> sortedWorkers = new TreeMap<>();
    for (int i = workers.length - k; i < workers.length; ++i)
      sortedWorkers.merge(workers[i], 1, Integer::sum);

    // Out of the k smallest tasks, start from the biggest one.
    for (int i = k - 1; i >= 0; --i) {
      // Find the first worker that has strength >= tasks[i].
      Integer lo = sortedWorkers.ceilingKey(tasks[i]);
      if (lo != null) {
        sortedWorkers.merge(lo, -1, Integer::sum);
        if (sortedWorkers.get(lo) == 0) {
          sortedWorkers.remove(lo);
        }
      } else if (pillsLeft > 0) {
        // Find the first worker that has strength >= tasks[i] - strength.
        lo = sortedWorkers.ceilingKey(tasks[i] - strength);
        if (lo != null) {
          sortedWorkers.merge(lo, -1, Integer::sum);
          if (sortedWorkers.get(lo) == 0) {
            sortedWorkers.remove(lo);
          }
          --pillsLeft;
        } else {
          return false;
        }
      } else {
        return false;
      }
    }

    return true;
  }
}
