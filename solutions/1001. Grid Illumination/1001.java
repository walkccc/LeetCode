class Solution {
  public int[] gridIllumination(int n, int[][] lamps, int[][] queries) {
    List<Integer> ans = new ArrayList<>();
    Map<Integer, Integer> rows = new HashMap<>();
    Map<Integer, Integer> cols = new HashMap<>();
    Map<Integer, Integer> diag1 = new HashMap<>();
    Map<Integer, Integer> diag2 = new HashMap<>();
    Set<Long> lampsSet = new HashSet<>();

    for (int[] lamp : lamps) {
      final int i = lamp[0];
      final int j = lamp[1];
      if (lampsSet.add(hash(i, j))) {
        rows.merge(i, 1, Integer::sum);
        cols.merge(j, 1, Integer::sum);
        diag1.merge(i + j, 1, Integer::sum);
        diag2.merge(i - j, 1, Integer::sum);
      }
    }

    for (int[] query : queries) {
      final int i = query[0];
      final int j = query[1];
      if (rows.getOrDefault(i, 0) > 0 || cols.getOrDefault(j, 0) > 0 ||
          diag1.getOrDefault(i + j, 0) > 0 || diag2.getOrDefault(i - j, 0) > 0) {
        ans.add(1);
        for (int y = Math.max(0, i - 1); y < Math.min(n, i + 2); ++y)
          for (int x = Math.max(0, j - 1); x < Math.min(n, j + 2); ++x)
            if (lampsSet.remove(hash(y, x))) {
              rows.merge(y, 1, Integer::sum);
              cols.merge(x, 1, Integer::sum);
              diag1.merge(y + x, 1, Integer::sum);
              diag2.merge(y - x, 1, Integer::sum);
            }
      } else {
        ans.add(0);
      }
    }

    return ans.stream().mapToInt(Integer::intValue).toArray();
  }

  private long hash(int i, int j) {
    return ((long) i << 32) + j;
  }
}
