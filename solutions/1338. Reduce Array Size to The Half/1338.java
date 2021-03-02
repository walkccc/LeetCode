class Solution {
  public int minSetSize(int[] arr) {
    final int n = arr.length;

    int sum = 0;
    Map<Integer, Integer> map = new HashMap<>();

    for (int a : arr)
      map.put(a, map.getOrDefault(a, 0) + 1);

    int[][] count = new int[map.size()][2];
    int i = 0;

    for (int key : map.keySet()) {
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
