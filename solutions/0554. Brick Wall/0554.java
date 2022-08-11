class Solution {
  public int leastBricks(List<List<Integer>> wall) {
    int maxFreq = 0;
    Map<Integer, Integer> count = new HashMap<>();

    for (List<Integer> row : wall) {
      int prefix = 0;
      for (int i = 0; i < row.size() - 1; ++i) {
        prefix += row.get(i);
        count.put(prefix, count.getOrDefault(prefix, 0) + 1);
        maxFreq = Math.max(maxFreq, count.get(prefix));
      }
    }

    return wall.size() - maxFreq;
  }
}
