class Solution {
  public boolean canReorderDoubled(int[] arr) {
    Map<Integer, Integer> count = new HashMap<>();

    for (final int a : arr)
      count.merge(a, 1, Integer::sum);

    arr = Arrays.stream(arr)
              .boxed()
              .sorted((a, b) -> Integer.compare(Math.abs(a), Math.abs(b)))
              .mapToInt(i -> i)
              .toArray();

    for (final int a : arr) {
      if (count.get(a) == 0)
        continue;
      if (count.getOrDefault(2 * a, 0) == 0)
        return false;
      count.merge(a, -1, Integer::sum);
      count.merge(2 * a, -1, Integer::sum);
    }

    return true;
  }
}
