class Solution {
  public int minTransfers(int[][] transactions) {
    int[] balance = new int[21];
    List<Integer> debts = new ArrayList<>();

    for (int[] t : transactions) {
      final int from = t[0];
      final int to = t[1];
      final int amount = t[2];
      balance[from] -= amount;
      balance[to] += amount;
    }

    for (final int b : balance)
      if (b != 0)
        debts.add(b);

    return dfs(debts, 0);
  }

  private int dfs(List<Integer> debts, int s) {
    while (s < debts.size() && debts.get(s) == 0)
      ++s;
    if (s == debts.size())
      return 0;

    int ans = Integer.MAX_VALUE;

    for (int i = s + 1; i < debts.size(); ++i)
      if (debts.get(i) * debts.get(s) < 0) {
        debts.set(i, debts.get(i) + debts.get(s)); // `debts.get(s)` is settled.
        ans = Math.min(ans, 1 + dfs(debts, s + 1));
        debts.set(i, debts.get(i) - debts.get(s)); // Backtrack.
      }

    return ans;
  }
}
