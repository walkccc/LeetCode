class Solution {
  public boolean uniqueOccurrences(int[] arr) {
    Map<Integer, Integer> count = new HashMap<>();
    Set<Integer> occurrences = new HashSet<>();

    for (final int a : arr)
      count.merge(a, 1, Integer::sum);

    for (final int value : count.values())
      if (!occurrences.add(value))
        return false;

    return true;
  }
}
