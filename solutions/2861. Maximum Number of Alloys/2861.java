class Solution {
  public int maxNumberOfAlloys(int n, int k, int budget, List<List<Integer>> composition,
                               List<Integer> stock, List<Integer> cost) {
    int l = 1;
    int r = 1_000_000_000;

    while (l < r) {
      final int m = (l + r) / 2;
      if (isPossible(n, budget, composition, stock, cost, m))
        l = m + 1;
      else
        r = m;
    }

    return l - 1;
  }

  // Returns true if it's possible to create `m` alloys by using any machine.
  private boolean isPossible(int n, int budget, List<List<Integer>> composition,
                             List<Integer> stock, List<Integer> costs, int m) {
    // Try all the possible machines.
    for (List<Integer> machine : composition) {
      long requiredMoney = 0;
      for (int j = 0; j < n; ++j) {
        final long requiredUnits = Math.max(0L, (long) machine.get(j) * m - stock.get(j));
        requiredMoney += requiredUnits * costs.get(j);
      }
      if (requiredMoney <= budget)
        return true;
    }
    return false;
  }
}
