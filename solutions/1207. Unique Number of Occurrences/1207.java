class Solution {
  public boolean uniqueOccurrences(int[] arr) {
    Map<Integer, Integer> count = new HashMap<>();
    Set<Integer> occurrences = new HashSet<>();

    for (int a : arr)
      count.put(a, count.getOrDefault(a, 0) + 1);

    for (int value : count.values())
      if (!occurrences.add(value))
        return false;

    return true;
  }
}
