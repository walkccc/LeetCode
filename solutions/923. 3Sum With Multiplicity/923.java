class Solution {
  public int threeSumMulti(int[] arr, int target) {
    final int kMod = 1_000_000_007;
    int ans = 0;
    Map<Integer, Integer> count = new HashMap<>();

    for (final int a : arr)
      count.merge(a, 1, Integer::sum);

    for (Map.Entry<Integer, Integer> entry : count.entrySet()) {
      final int i = entry.getKey();
      final int x = entry.getValue();
      for (Map.Entry<Integer, Integer> entry2 : count.entrySet()) {
        final int j = entry2.getKey();
        final int y = entry2.getValue();
        final int k = target - i - j;
        if (!count.containsKey(k))
          continue;
        if (i == j && j == k)
          ans = (int) ((ans + (long) x * (x - 1) * (x - 2) / 6) % kMod);
        else if (i == j && j != k)
          ans = (int) ((ans + (long) x * (x - 1) / 2 * count.get(k)) % kMod);
        else if (i < j && j < k)
          ans = (int) ((ans + (long) x * y * count.get(k)) % kMod);
      }
    }

    return ans;
  }
}
