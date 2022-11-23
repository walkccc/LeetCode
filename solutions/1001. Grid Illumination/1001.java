class Solution {
  public int[] gridIllumination(int N, int[][] lamps, int[][] queries) {
    List<Integer> ans = new ArrayList<>();
    Map<Integer, Integer> rows = new HashMap<>();
    Map<Integer, Integer> cols = new HashMap<>();
    Map<Integer, Integer> diag1 = new HashMap<>();
    Map<Integer, Integer> diag2 = new HashMap<>();
    Set<Long> lampsSet = new HashSet<>();

    for (int[] lamp : lamps) {
      int i = lamp[0];
      int j = lamp[1];
      if (lampsSet.add(hash(i, j))) {
        rows.put(i, rows.getOrDefault(i, 0) + 1);
        cols.put(j, cols.getOrDefault(j, 0) + 1);
        diag1.put(i + j, diag1.getOrDefault(i + j, 0) + 1);
        diag2.put(i - j, diag2.getOrDefault(i - j, 0) + 1);
      }
    }

    for (int[] q : queries) {
      int i = q[0];
      int j = q[1];
      if (rows.getOrDefault(i, 0) > 0 || cols.getOrDefault(j, 0) > 0 ||
          diag1.getOrDefault(i + j, 0) > 0 || diag2.getOrDefault(i - j, 0) > 0) {
        ans.add(1);
        for (int y = Math.max(0, i - 1); y < Math.min(N, i + 2); ++y)
          for (int x = Math.max(0, j - 1); x < Math.min(N, j + 2); ++x)
            if (lampsSet.remove(hash(y, x))) {
              rows.put(y, rows.getOrDefault(y, 0) - 1);
              cols.put(x, cols.getOrDefault(x, 0) - 1);
              diag1.put(y + x, diag1.getOrDefault(y + x, 0) - 1);
              diag2.put(y - x, diag2.getOrDefault(y - x, 0) - 1);
            }
      } else
        ans.add(0);
    }

    return ans.stream().mapToInt(Integer::intValue).toArray();
  }

  private long hash(int i, int j) {
    return ((long) i << 32) + j;
  }
}
