class Solution {
  public boolean canReorderDoubled(int[] A) {
    Map<Integer, Integer> count = new HashMap<>();

    for (int a : A)
      count.put(a, count.getOrDefault(a, 0) + 1);

    A = Arrays.stream(A)
            .boxed()
            .sorted((a, b) -> Math.abs(a) - Math.abs(b))
            .mapToInt(i -> i)
            .toArray();

    for (int a : A) {
      if (count.get(a) == 0)
        continue;
      if (count.getOrDefault(2 * a, 0) == 0)
        return false;
      count.put(a, count.get(a) - 1);
      count.put(2 * a, count.get(2 * a) - 1);
    }

    return true;
  }
}
