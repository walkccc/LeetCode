class Solution {
  public int minSetSize(int[] arr) {
    final int n = arr.length;
    int sum = 0;
    Map<Integer, Integer> map = new HashMap<>();

    for (final int a : arr)
      map.merge(a, 1, Integer::sum);

    int[][] count = new int[map.size()][2];
    int i = 0;

    for (final int key : map.keySet()) {
      count[i][0] = key;
      count[i++][1] = map.get(key);
    }

    Arrays.sort(count, (c1, c2) -> c2[1] - c1[1]);

    for (i = 0; i < count.length; ++i) {
      sum += count[i][1];
      if (sum >= n / 2)
        return i + 1;
    }

    throw new IllegalArgumentException();
  }
}
