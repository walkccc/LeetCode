class Solution {
  public int countPairs(List<List<Integer>> coordinates, int k) {
    int ans = 0;

    for (int x = 0; x <= k; ++x) {
      final int y = k - x;
      Map<Pair<Integer, Integer>, Integer> count = new HashMap<>();
      for (List<Integer> point : coordinates) {
        final int xi = point.get(0);
        final int yi = point.get(1);
        ans += count.getOrDefault(new Pair<>(xi ^ x, yi ^ y), 0);
        count.merge(new Pair<>(xi, yi), 1, Integer::sum);
      }
    }

    return ans;
  }
}
