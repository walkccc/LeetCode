class Solution {
  public boolean canReorderDoubled(int[] A) {
    Map<Integer, Integer> count = new HashMap<>();

    for (final int a : A)
      count.merge(a, 1, Integer::sum);

    A = Arrays.stream(A)
            .boxed()
            .sorted((a, b) -> Math.abs(a) - Math.abs(b))
            .mapToInt(i -> i)
            .toArray();

    for (final int a : A) {
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
