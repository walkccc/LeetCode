class Solution {
  public List<Integer> cheapestJump(int[] coins, int maxJump) {
    if (coins[coins.length - 1] == -1)
      return new ArrayList<>();

    int n = coins.length;
    int[] next = new int[n];
    Arrays.fill(next, -1);
    int[] mem = new int[n];
    Arrays.fill(mem, Integer.MAX_VALUE);
    cheapestJump(coins, maxJump, 0, next, mem);

    if (mem[0] == Integer.MAX_VALUE)
      return new ArrayList<>();
    return constructPath(next, 0);
  }

  // Returns the minimum cost to jump from i to n - 1.
  private int cheapestJump(int[] coins, int maxJump, int i, int[] next, int[] mem) {
    if (i == coins.length - 1)
      return mem[i] = coins[i];
    if (mem[i] < Integer.MAX_VALUE)
      return mem[i];
    if (coins[i] == -1)
      return Integer.MAX_VALUE;

    for (int j = i + 1; j <= Math.min(i + maxJump, coins.length - 1); ++j) {
      final int res = cheapestJump(coins, maxJump, j, next, mem);
      if (res == Integer.MAX_VALUE)
        continue;
      final int cost = coins[i] + res;
      if (cost < mem[i]) {
        mem[i] = cost;
        next[i] = j;
      }
    }

    return mem[i];
  }

  private List<Integer> constructPath(int[] next, int i) {
    List<Integer> ans = new ArrayList<>();
    while (i != -1) {
      ans.add(i + 1); // 1-indexed
      i = next[i];
    }
    return ans;
  }
}
