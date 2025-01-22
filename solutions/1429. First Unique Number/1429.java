class FirstUnique {
  public FirstUnique(int[] nums) {
    for (final int num : nums)
      add(num);
  }

  public int showFirstUnique() {
    return unique.isEmpty() ? -1 : unique.iterator().next();
  }

  public void add(int value) {
    if (!seen.contains(value)) {
      unique.add(value);
      seen.add(value);
    } else if (unique.contains(value)) {
      // We have added this value before, and this is the second time we're
      // adding it. So, erase the value from `unique`.
      unique.remove(value);
    }
  }

  private Set<Integer> seen = new HashSet<>();
  private Set<Integer> unique = new LinkedHashSet<>();
}
