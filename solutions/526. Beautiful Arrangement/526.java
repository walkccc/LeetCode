class Solution {
  public int countArrangement(int n) {
    final String filled = "x".repeat(n + 1);
    StringBuilder sb = new StringBuilder(filled);
    Map<String, Integer> mem = new HashMap<>();

    return dfs(n, 1, sb, mem);
  }

  private int dfs(int n, int num, StringBuilder sb, Map<String, Integer> mem) {
    if (num == n + 1)
      return 1;
    final String filled = sb.toString();
    if (mem.containsKey(filled))
      return mem.get(filled);

    int count = 0;

    for (int i = 1; i <= n; ++i)
      if (sb.charAt(i) == 'x' && (num % i == 0 || i % num == 0)) {
        sb.setCharAt(i, 'o');
        count += dfs(n, num + 1, sb, mem);
        sb.setCharAt(i, 'x');
      }

    mem.put(filled, count);
    return count;
  }
}
