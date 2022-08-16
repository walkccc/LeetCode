class Solution {
  public int minTransfers(int[][] transactions) {
    int[] balance = new int[21];
    List<Integer> debt = new ArrayList<>();

    for (int[] t : transactions) {
      final int from = t[0];
      final int to = t[1];
      final int amount = t[2];
      balance[from] -= amount;
      balance[to] += amount;
    }

    for (final int b : balance)
      if (b != 0)
        debt.add(b);

    return dfs(debt, 0);
  }

  private int dfs(List<Integer> debt, int s) {
    while (s < debt.size() && debt.get(s) == 0)
      ++s;
    if (s == debt.size())
      return 0;

    int ans = Integer.MAX_VALUE;

    for (int i = s + 1; i < debt.size(); ++i)
      if (debt.get(i) * debt.get(s) < 0) {
        debt.set(i, debt.get(i) + debt.get(s)); // debt.get(s) is settled
        ans = Math.min(ans, 1 + dfs(debt, s + 1));
        debt.set(i, debt.get(i) - debt.get(s)); // backtrack
      }

    return ans;
  }
}
