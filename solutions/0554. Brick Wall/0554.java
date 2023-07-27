class Solution {
  public int leastBricks(List<List<Integer>> wall) {
    int maxFreq = 0;
    Map<Integer, Integer> count = new HashMap<>();

    for (List<Integer> row : wall) {
      int prefix = 0;
      for (int i = 0; i < row.size() - 1; ++i) {
        prefix += row.get(i);
        maxFreq = Math.max(maxFreq, count.merge(prefix, 1, Integer::sum));
      }
    }

    return wall.size() - maxFreq;
  }
}
