class Solution {
  public int leastBricks(List<List<Integer>> wall) {
    int maxFreq = 0;
    Map<Integer, Integer> count = new HashMap<>();

    for (List<Integer> row : wall) {
      int prefixSum = 0;
      for (int i = 0; i < row.size() - 1; ++i) {
        prefixSum += row.get(i);
        count.put(prefixSum, count.getOrDefault(prefixSum, 0) + 1);
        maxFreq = Math.max(maxFreq, count.get(prefixSum));
      }
    }

    return wall.size() - maxFreq;
  }
}